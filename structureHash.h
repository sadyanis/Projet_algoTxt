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

Trie trie_pref(unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);


Trie trie_suff(unsigned char *w);

List createNewTransition(int startNode, unsigned char letter, int targetNode);

List findExistingTransition(Trie trie,int hachCode, int currentNode,char letter);
#endif