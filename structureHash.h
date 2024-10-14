#ifndef STRUCTUREHASH_H
#define STRUCTUREHASH_H
struct _list{
    int startNode,targetNode;
    unsigned char letter;
    struct _list *next;

} ;
typedef struct _list *List;

struct _trie {
    int maxNode; //nbt max de noeud
    int nextNode;
    List *transition; // table hachage
    char *finite;
};

typedef struct _trie *Trie;

Trie createTrie(int maxNode);

unsigned int hash_function(char c, int num);

void insertInTrie(Trie trie, unsigned char *w);

Trie trie_pref(unsigned char *w,int maxNode);

int isInTrie(Trie trie, unsigned char *w);


Trie trie_suff(unsigned char *w,int maxNode);

List findTransition(List transitions, int currentNode, unsigned char letter);

int isTransitionValid(List transition, int currentNode, unsigned char letter);

void initialiser( List ** matriceHach , int tableSize);



#endif