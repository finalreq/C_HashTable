#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int val;
	struct node* next;
}Node;

int main(){
	int i = 0;
	Node *hash = (Node*)malloc (sizeof (Node)*13);
	for (i = 0; i<13; i++){
		hash[i].val = i;
		hash[i].next = (Node*) malloc (sizeof (Node));
	}
	hash[1].next->val = 17;

	printf ("%d, %d \n", hash[1].val, hash[1].next->val);
	
	printf ("Hello World! %d\n", i);
	return 0;
}
