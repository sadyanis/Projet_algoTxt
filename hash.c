#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include "structureHash.h"



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
        if (trie->transition[hashcode]==NULL)
        {
            List newTrans = malloc(sizeof(struct _list));
            newTrans->startNode = currentNode;
            newTrans->letter = w[i];
            newTrans->targetNode = trie->nextNode;
            newTrans->next = NULL;
            currentNode = trie->nextNode;
            trie->nextNode = trie->nextNode + 1;
            trie->transition[hashcode] = newTrans;
        }else{
            List point = trie->transition[hashcode];
            while (point != NULL)
            {
                if (point->startNode == currentNode && point->letter == w[i])
                {
                    currentNode = point->targetNode;
                    break;
                }
                point=point->next;
                /* code */
            }
            // si y'a pas de transition avec la meme lettre 
            if (point == NULL)
            {
                 List newTrans = malloc(sizeof(struct _list));
            newTrans->startNode = currentNode;
            newTrans->letter = w[i];
            newTrans->targetNode = trie->nextNode;
            currentNode = trie->nextNode;
            trie->nextNode = trie->nextNode + 1;
            // inserer au debut
            newTrans->next = trie->transition[hashcode];
            trie->transition[hashcode] = newTrans;
                //creation d'une transition
                // fonction pour inserer en debut
            }
            
            
        }

        
    }
    trie->finite[currentNode] = 1;

    
}

int isInTrie(Trie trie, unsigned char *w){
int wordLength = strlen((char *)w);
    int i = 0;
    int current_node = 0;
    int hashcode;
    while(i<wordLength){
        hashcode = hash_function(w[i],current_node);
        if (trie->transition[hashcode]== NULL)
        {
            return 1; // 1 -> false & 0 -> true
            /* code */
        }else{
             List point = trie->transition[hashcode];
            while (point != NULL)
            {
                if (point->startNode == current_node && point->letter == w[i])
                {
                    current_node = point->targetNode;
                    break;
                }
                point=point->next;
                /* code */
            }
        }
        i++;
        
    }
    if (trie->finite[current_node]==0)
    {
        return 1;
        /* code */
    }
    return 0 ;

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

// fonction pour creer une nouvelle transition

List createNewTransition(int startNode, unsigned char letter, int targetNode) {
    List newTrans = malloc(sizeof(struct _list));
    newTrans->startNode = startNode;
    newTrans->letter = letter;
    newTrans->targetNode = targetNode;
    newTrans->next = NULL;
    return newTrans;
}





