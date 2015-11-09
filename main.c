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
		if (tmp->val == n->val){
			printf ("ERROR: The value is already in the hash table\n");
			printf ("value in table %d, val to enter %d\n", tmp->val, n->val);
			return 0;
		}
		tmp = tmp->next;
	}
	tmp->next = n;
	return 1;
}

void print_table (Node *table){
	Node* tmp = malloc (sizeof (Node));
	int i = 0;
	for (i = 0; i < 13; i++){	
		printf ("Table[i].val = ");
		tmp = &table[i];
		while (tmp->next != NULL){
			printf ("%d ---> ", tmp->val);
			tmp = tmp->next;
		}
		printf ("%d\n", tmp->val);
	}
	
}

void find_value (Node table){
	
}

int main(){
	int i = 0;
	int val = 0;
	int option = 0;
	Node *hash = (Node*)malloc (sizeof (Node)*13);
	if (hash[1].next == NULL){
		printf ("this?\n");
	}
	
	//Node *n = malloc (sizeof(Node));
	while (1){
		printf ("1 ........ Add value to hash table\n2 ........ Find value in hash table\n3 ........ Print table\n");
		scanf("%d", &option);
		if (option == 1){
			printf ("Please enter a value to add: ");
			scanf ("%d", &val);
			Node *n = malloc (sizeof (Node));
			n->val = val;
			n->next = NULL;
			add_node(hash, n);
			//free(n);
		}
		else if (option == 2){
			//TODO do the find function
		}
		else if (option == 3){
			print_table (hash);
		}
		else{
			printf ("Not a valid option \n");
		}
	}
	/*n->val = 14;
	n->next = NULL;
	add_node (hash, n);
	printf ("%d, %d, %d \n", hash[1].val, hash[1].next->val, hash[1].next->next->val);
	if (hash[5].next == NULL){
		printf ("ha\n");
	}*/
	printf ("Hello World! %d\n", i);
	return 0;
}
