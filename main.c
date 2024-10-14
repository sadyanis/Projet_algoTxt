#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include "structures.h"

 int main(int argc, char const *argv[]){
    //test
    Trie tr =  createTrie(6);
    unsigned char *w = (unsigned char *)"ab" ;
    unsigned char *w1 = (unsigned char *)"abab";
    unsigned char *w2 = (unsigned char *)"abac";
   
    insertInTrie(tr,w) ;  
    insertInTrie(tr,w1) ;
     int result = isInTrie(tr,w);
    printf("%d",result);

    return 0;
}

Trie createTrie(int maxNode){
    //initialisation
    Trie monTrie = malloc(sizeof(struct _trie));
    //controle d'erreur
    monTrie->maxNode = maxNode;
    monTrie->nextNode = 1;
    monTrie->transition = malloc(maxNode * sizeof(int *));

    monTrie->finite = malloc(maxNode * sizeof(char));
    //initialisation du tableau par des 0
    memset(monTrie->finite,0,maxNode * sizeof(char));
    // initialisation de la matrice
     initialiser(monTrie->transition,maxNode);
    //controle d'erreur

    return monTrie;

}
// fonction pour inserer un mot

void insertInTrie(Trie trie, unsigned char *w){
    int n = strlen((char *)w);
    int current_node = 0;
    for (int i = 0; i < n; i++)
    {
        if (trie->transition[current_node][w[i]] == -1)
        {
            trie->transition[current_node][w[i]] = trie->nextNode;
            //trie->finite[current_node] = 0; // current node n'est plus un terminal
            current_node = trie->nextNode;
            trie->nextNode = trie->nextNode + 1;
            
        }else{
            current_node = trie->transition[current_node][w[i]];

        }
        trie->finite[current_node] = 1; //est un terminal
        
    }
    

    return ;
}
// fonction pour initialiser une matrice
void initialiser(int ** matrice , int max_node){
    for (int i = 0; i < max_node ; i++)
    {
        matrice[i] = malloc(UCHAR_MAX * sizeof( int));
        if (matrice[i]==NULL){
            perror("erreur d'allocation");
        }
        memset(matrice[i],-1,UCHAR_MAX * sizeof(int));
    }
    
}

// fonction pour savoir si un mot est dans un trie
int isInTrie(Trie trie, unsigned char *w){
    int N = strlen((char *)w);
    int i = 0;
    int current_node = 0;
    while (i < N)
    {
        if(trie->transition[current_node][w[i]] == -1){
            return 1;
        }else
        current_node = trie->transition[current_node][w[i]];
        i++;
        
        /* code */

    }
    if(trie->finite[current_node]== 0){
    return 1;
    }
    return 0;
    
}
//fonction qui construit un trie pour les prefix
Trie trie_pref(unsigned char *w,int maxNode){
    Trie tr =  createTrie(maxNode);
    insertInTrie(tr,w);
    for (int i = 0; i < tr->nextNode; i++)
    {   
        // tous les noeud devienne finaux
        tr->finite[i] = 1;
        /* code */
    }
    return tr;
    
}

Trie trie_suff(unsigned char *w,int maxNode){
    Trie tr =  createTrie(maxNode);
    int n = strlen((char *)w);
    for (int i = 0; i < n; i++)
    {
        insertInTrie(tr,w+i);
        /* code */
    }
    return tr;
}
// fonction de hachage retourne un entier
// int hashFunc(int etat,unsigned char caractere){

// }

