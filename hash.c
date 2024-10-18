#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include "structureHash.h"


#define TRUE 0
#define FALSE 1
#define TABLE_SIZE 101  // Un nombre premier proche du nombre d'éléments prévus a definir plutard




int main() {

    unsigned char *w = (unsigned char *)"absdasd" ;
    unsigned char *w1 = (unsigned char *)"absdasd" ;
    Trie tr = createTrie(8);
    insertInTrie(tr,w);
    printf("%d",isInTrie(tr,w1));
    


    
    

    return 0;
}
//
Trie createTrie(int maxNode){
    Trie tr = malloc(sizeof(struct _trie));
   if (tr == NULL)
   {
    perror("Error allocation");
    exit(EXIT_FAILURE);
   }
   tr->maxNode = maxNode;
   tr->nextNode = 1;
   tr->finite =(char*) malloc(maxNode * sizeof(char));
   //initialisation du tableau par des 0
    memset(tr->finite,0,maxNode * sizeof(char));
   // initialisation de la table de hachage
   tr->transition = malloc(TABLE_SIZE * sizeof(List));
    if (tr->transition == NULL) {
        perror("Error allocation");
        exit(EXIT_FAILURE);
    }

    // Initialiser chaque élément de `transition` à NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        tr->transition[i] = NULL;
    }
    
    return tr;
    
}

void insertInTrie(Trie trie, unsigned char *w){
    int wordLength = strlen((char *)w);
    int currentNode = 0;
    int hashcode;
    for (int i = 0; i < wordLength; i++)
    {
        hashcode = (hash_function(w[i],currentNode));
        List point = findExistingTransition(trie,hashcode,currentNode,w[i]);
        if (point==NULL)
        {
            List newTrans = createNewTransition(currentNode,w[i],trie->nextNode);
            newTrans->next = trie->transition[hashcode]; // inserer en tete
             trie->transition[hashcode] = newTrans;
            currentNode = trie->nextNode;
            trie->nextNode += 1;
           
        }else{
            currentNode = point->targetNode;
        }
        
    }
    trie->finite[currentNode] = 1;    
}

int isInTrie(Trie trie, unsigned char *w) {
    int wordLength = strlen((char *)w);
    int currentNode = 0;
    int hashcode;

    for (int i = 0; i < wordLength; i++) {
        hashcode = hash_function(w[i], currentNode);
        
        List point = findExistingTransition(trie, hashcode, currentNode, w[i]);
        
        if (point == NULL) {
            return FALSE; // Mot non trouvé
        }
        
        currentNode = point->targetNode;
    }

    return (trie->finite[currentNode] == 1) ? TRUE : FALSE;
}

Trie trie_pref(unsigned char *w){
   
     int maxNode  = strlen((char *)w) + 1;//taille du mot +1
    Trie trie = createTrie(maxNode);
    insertInTrie(trie,w);
    for (int i = 0; i < maxNode; i++)
    {
        trie->finite[i]=1;
        
    }
    return trie;
    
}

Trie trie_suff(unsigned char *w){
    int maxNode  = strlen((char *)w) + 1;//taille du mot +1
    Trie trie = createTrie(maxNode);
    for (int i = 0; i < maxNode-1; i++)
    {
        insertInTrie(trie,w+1);
        /* code */
    }
    return trie;
}

Trie trie_facteur(unsigned char *w){
    int maxNode  = strlen((char *)w) + 1;//taille du mot +1
    Trie trie = createTrie(maxNode);
     for (int i = 0; i < maxNode-1; i++) {
        // Insérer chaque suffixe qui commence à i
        for (int j = i + 1; j <= maxNode-1; j++) {
            // Insérer tous les préfixes de ce suffixe
            unsigned char *factor = strndup((char *)(w + i), j - i);
            insertInTrie(trie, factor);
            free(factor);
        }
    }
    return trie;
}


unsigned int hash_function(char c, int num) {
    unsigned int hash = 0;
    
    // Utilisation du caractère ASCII
    hash = (unsigned int)c;
    
    // Incorporation de l'entier
    hash = hash * 31 + num;
    
    // Réduction de la valeur de hachage avec le modulo
    hash = hash % TABLE_SIZE;
    
    return hash;
 }




// fonction pour creer une nouvelle transition

List createNewTransition(int startNode, unsigned char letter, int targetNode) {
    List newTrans = malloc(sizeof(struct _list));
    newTrans->startNode = startNode;
    newTrans->letter = letter;
    newTrans->targetNode = targetNode;
    newTrans->next = NULL;
    return newTrans;
}

List findExistingTransition(Trie trie,int hachCode, int currentNode,char letter){
    List pointeur = trie->transition[hachCode];
    while (pointeur != NULL)
    {
        if (pointeur->startNode == currentNode && pointeur->letter == letter)
        {
            return pointeur;
        }
        pointeur =  pointeur->next;
        
    }
    return NULL;
}




