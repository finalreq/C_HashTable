#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int val;
	struct node* next;
}Node;

int gethash (int n){
	int hash = n % 13;
	return hash;
}

int add_node (Node *table, Node *n){
	int hash = gethash(n->val);
	Node* tmp = &table[hash];
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = n;
	return 1;
}


int main(){
	int i = 0;
	Node *hash = (Node*)malloc (sizeof (Node)*13);
	for (i = 0; i<13; i++){
		hash[i].val = i;
		hash[i].next = (Node*) malloc (sizeof (Node));
	}
	hash[1].next->val = 17;
	Node *n = malloc (sizeof(Node));
	n->val = 14;
	n->next = NULL;
	add_node (hash, n);
	printf ("%d, %d, %d \n", hash[1].val, hash[1].next->val, hash[1].next->next->val);
	if (hash[5].next == NULL){
		printf ("ha\n");
	}
	printf ("Hello World! %d\n", i);
	return 0;
}
