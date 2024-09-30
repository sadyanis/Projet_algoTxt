#ifndef STRUCTURES_H
#define STRUCTURES_H
//struct de table de table de transition
struct _trie {
    int maxNode; //nbt max de noeud
    int nextNode;
    int **transition;
    char *finite;
};
// struct de la table de hashage

struct _list{
    int startNode,targetNode;
    unsigned char letter;
    struct _list *next;

} ;

typedef struct _trie *Trie;

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);

void initialiser(int ** matrice , int max_node);

void insertInTrie(Trie trie , unsigned char *w);

#endif
//memset