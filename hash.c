#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include "structureHash.h"



#define TABLE_SIZE 101  // Un nombre premier proche du nombre d'éléments prévus a definir plutard




int main() {

    unsigned char *w1  = "hello";
    unsigned char *w2  = "hello";
    Trie tr = createTrie(8);
    printf("%d",tr->nextNode);
    
    

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
   initialiser(tr->transition, maxNode);
    
    return tr;
    
}

/* void insertInTrie(Trie trie, unsigned char *w){
    int n = strlen((char *)w);
    int current_node = 0; // ne node courant
    int hashcode ; // va contenir le resultat de la fonction de hachage
    int lastNode =  trie[TABLE_SIZE].targetNode ; // recupere le dernier node qui est stocké sur la derniere case 
    for (int i = 0; i < n; i++)
    {
        hashcode = (hash_function(w[i],current_node));
        if(trie[hashcode].startNode == -1){
            trie[hashcode].startNode = current_node;
            
            trie[hashcode].letter = w[i];
            trie[hashcode].next = NULL;
            
            if (i == n-1)
            {
                
                trie[hashcode].targetNode = -1 ; // pour determiner si cet etat est terminal
                
            }else{
                trie[hashcode].targetNode = lastNode ;
                current_node = lastNode;
                lastNode+=1;
            }
            

        }else {
            List pnt ;
            List last = NULL;
            pnt = trie+hashcode;
            while(pnt != NULL){
                if(pnt->startNode==current_node && pnt->letter == w[i] ){
                   current_node = pnt->targetNode;
                   break; // sortir de la boucle 
                }
                last = pnt ; // sauvegarder la valeur precedante
                pnt = pnt->next;
            }
            if(pnt == NULL){
                // creation d'une nouvelle transition
                List new = malloc(sizeof(struct _list));
                new->startNode = current_node;
                new->letter = w[i];
                 new->next = NULL;
                if(i == n -1){new->targetNode = -1;   }
                else{       
                new->targetNode = lastNode;
                last->next = new ;
                current_node = lastNode;
                lastNode++;
               

                //enfiler la nouvelle transition en fin 
                }
            }
        }
        trie[TABLE_SIZE].targetNode = lastNode;
        
    }
    

}*/

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

// fonction pour savoir si un mot appartien au trie ou pas
/* int isInTrie(List trie, unsigned char *w){
    int N = strlen((char *)w);
    int i = 0;
    int current_node = 0;
    int hash;
    while(i<N){
        hash = hash_function(w[i],current_node);
        // parcourir pour chercher les transition
        List pnt = &trie[hash];
        //parcourir 
        while(pnt != NULL){
            if(pnt->startNode == -1){
                return 0;
            }
            if(pnt->startNode == current_node && pnt->letter ==w[i]){
                current_node = pnt->targetNode;
                break;
            }
            pnt = pnt->next;
        }
        if (pnt == NULL)
        {
            return 0 ; // mot non trouvé
            
        }
        i++;

        if(current_node == -1){
            return 1;
        }
        

    }
    return 0;
}*/
/*int isInTrie(List trie, unsigned char *word) {
    int wordLength = strlen((char *)word);
    int currentNode = 0;

    for (int currentIndex = 0; currentIndex < wordLength; currentIndex++) {
        int hashCode = hash_function(word[currentIndex], currentNode);
        List currentTransition = findTransition(&trie[hashCode], currentNode, word[currentIndex]);

        // Si aucune transition trouvée, mot non trouvé
        if (currentTransition == NULL) {
            return 0; // Mot non trouvé
        }

        currentNode = currentTransition->targetNode; // Mettre à jour le nœud courant
    }

    // Vérifier si le nœud courant est terminal
    return (currentNode == -1) ? 1 : 0; // Mot trouvé ou non
}*/

int isTransitionValid(List transition, int currentNode, unsigned char letter) {
    return transition->startNode == currentNode && transition->letter == letter;
}

List findTransition(List transitions, int currentNode, unsigned char letter) {
    while (transitions != NULL) {
        if (isTransitionValid(transitions, currentNode, letter)) {
            return transitions; // Transition trouvée
        }
        transitions = transitions->next;
    }
    return NULL; // Aucune transition trouvée
}

void initialiser( struct _list ** matriceHach , int tableSize){
    matriceHach = malloc(tableSize * sizeof(List));
    if (matriceHach == NULL)
    {
        perror("allocation fault");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < tableSize; i++)
    {
        matriceHach[i]== NULL;
    }
    
    
}





