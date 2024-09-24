#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
    Trie tr =  createTrie(6);
    printf("%d \n",tr->maxNode);
    printf("%d",tr->nextNode);
    for (int i = 0; i < 6; i++)
    {
        printf("%d",tr->finite[i]);
        /* code */
    }
    


    return 0;
}

Trie createTrie(int maxNode){
    //initialisation
    Trie monTrie = malloc(sizeof(struct _trie));
    //controle d'erreur
    monTrie->maxNode = maxNode;
    monTrie->nextNode = 0;
    monTrie->transition = malloc(maxNode * sizeof(int *));

    monTrie->finite = malloc(maxNode * sizeof(int));
    //initialisation du tableau
    memset(monTrie->finite,0,maxNode * sizeof(int));
    //controle d'erreur

    return monTrie;

}

void insertInTrie(Trie trie, unsigned char *w){

    return ;
}