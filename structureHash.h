#ifndef STRUCTUREHASH_H
#define STRUCTUREHASH_H
struct _list{
    int startNode,targetNode;
    unsigned char letter;
    struct _list *next;

} ;

typedef struct _list *List;

List createTrie(int maxNode);

unsigned int hash_function(char c, int num);

void insertInTrie(List trie, unsigned char *w);

int isInTrie(List trie, unsigned char *w);


List trie_pref(unsigned char *w,int maxNode);

int isInTrie(List trie, unsigned char *w);

List trie_suff(unsigned char *w,int maxNode);

List findTransition(List transitions, int currentNode, unsigned char letter);

int isTransitionValid(List transition, int currentNode, unsigned char letter);




#endif