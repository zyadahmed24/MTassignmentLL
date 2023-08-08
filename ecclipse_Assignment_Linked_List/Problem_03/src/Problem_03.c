/*
 ============================================================================
 Name        : Problem_03.c
 Author      : zyad ahmed
 Version     :
 Copyright   : out of order........, I will show you the out of order
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};
typedef struct node  node;


node* makeLinkedList(int ,int);
void printLikedList(node* head);
void printFifthElement(node* head);

int main(void) {
	setbuf(stdout,NULL);
	int num;
	node* head=NULL;
	printf("enter a number above 5:");
	scanf("%d",&num);
	head = makeLinkedList(num,40);
	printLikedList(head);
	printFifthElement(head);
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

void printLikedList(node* head)
{
	node* current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}

void printFifthElement(node* head)
{
	node* ptr = head;
	if(head->next == NULL)
	{
		printf("its only one node:%d",head->data);
		return;
	}
	while(ptr->next->next->next->next->next != NULL)
	{
		ptr = ptr->next;
	}
	printf("the fifth data is:%d",ptr->data);
}
