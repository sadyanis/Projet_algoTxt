#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include "structureHash.h"

#include <stdio.h>

#define TABLE_SIZE 101  // Un nombre premier proche du nombre d'éléments prévus a definir plutard




int main() {
    // char c = 'c';
    // int num = 4;
    
    // unsigned int hash_value = hash_function(c, num);
    // printf("Hash value: %u\n", hash_value);
    unsigned char *w1  = "hello";
    List tr = createTrie(TABLE_SIZE);
    insertInTrie(tr,w1);
    printf("Hello\n");
    printf("%d,%d,%c",tr[hash_function('h',0)].startNode,tr[hash_function('h',0)].targetNode,tr[hash_function('h',0)].letter);

    return 0;
}
//
List createTrie(int maxNode){
    List tr = malloc((maxNode+1) * sizeof(struct _list));
    if(tr == NULL){
        perror("malloc fault");
    }
    for (int i = 0; i < maxNode; i++)
    {
        //initialisation
        tr[i].startNode = -1 ;
    }
    tr[TABLE_SIZE].targetNode = 1;
    
    return tr;
    
}

void insertInTrie(List trie, unsigned char *w){
    int n = strlen((char *)w);
    int current_node = 0;
    int hashcode ;
    int lastNode =  trie[TABLE_SIZE].targetNode ;
    for (int i = 0; i < n; i++)
    {
        hashcode = (hash_function(w[i],current_node));
        if(trie[hashcode].startNode == -1){
            trie[hashcode].startNode = current_node;
            trie[hashcode].targetNode = lastNode ;
            trie[hashcode].letter = w[i];
            trie[hashcode].next = NULL;
            current_node = lastNode;
            lastNode+=1;
        }else if(trie[hashcode].startNode== current_node && trie[hashcode].letter == w[i] ) {
            // a completer
            current_node = trie[hashcode].targetNode;

        }else{
            List new = malloc(sizeof(struct _list));
            new->startNode = current_node;
            new->targetNode = lastNode;
            new->letter = w[i];
            new->next = NULL;
            current_node = lastNode;
            lastNode+=1;
        }
        trie[TABLE_SIZE].targetNode = lastNode;
        /* code */
    }
    

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