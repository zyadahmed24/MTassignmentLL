/*
 ============================================================================
 Name        : Problem_01.c
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
void insertAtPosition(node*,int ,int);
void printLikedList(node* head);



int main(void) {
	setbuf(stdout,NULL);
	node* head;
	head = makeLinkedList(7,23);
	printLikedList(head);
	printf("\n");
	insertAtPosition(head,30,2);
	printLikedList(head);
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


void insertAtPosition(node* head,int data ,int pos)
{
	node* ptr;
	node* current;
	ptr = (node*) malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;


	int i=0;
	current = head;
	while(i != pos-1)
	{
		current = current->next;
		i++;
	}
	ptr->next = current->next;
	current->next = ptr;
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
