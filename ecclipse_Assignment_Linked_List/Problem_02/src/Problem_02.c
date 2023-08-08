/*
 ============================================================================
 Name        : Problem_02.c
 Author      : zyad ahmed
 Copyright   : out of order........, I will show you the out of order
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};
typedef struct node  node;


void printTheMiddleOfLinkedList(node*);
node* makeLinkedList(int ,int);
void printLikedList(node* head);

int main(void) {
	setbuf(stdout,NULL);
	int num;
	node* head=NULL;
	printf("enter an odd number:");
	scanf("%d",&num);
	head = makeLinkedList(num,40);
	printLikedList(head);
	printTheMiddleOfLinkedList(head);
	return EXIT_SUCCESS;
}

node* makeLinkedList(int nodes,int data)
{
	node* head = NULL;
	node** ptr = NULL;	//pointer to pointer to move throw the linked list.
	int i=nodes;

	while(i>0)
	{
		if(i == nodes)
		{
			head = (node*) malloc(sizeof(node));
			head->data = data-(2*i);
			head->next = NULL;
			ptr = &head;
			i--;
			continue;
		}
		(**ptr).next = (node*) malloc(sizeof(node));
		ptr = &(**ptr).next;
		(**ptr).data = data-(i);
		i--;
	}
	(**ptr).next = NULL;
	return head;
}

void printTheMiddleOfLinkedList(node*head)
{
	node* ptr1 = head;
	node* ptr2 = head;
	if(head->next == NULL)
	{
		printf("its only one node:%d",head->data);
		return;
	}
	while(ptr2->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		//ptr2 = ptr2->next;
	}
	printf("the middle data is:%d",ptr1->data);
}

void printLikedList(node* head)
{
	node* current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}
