/*
 ============================================================================
 Name        : Problem_05.c
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


node* makeLinkedList(int ,int);
void printLikedList(node* head);
void printLinkedListMax(node* head);

int main(void) {
	setbuf(stdout,NULL);
	int num;
	node* head=NULL;
	printf("enter a number above 5:");
	scanf("%d",&num);
	head = makeLinkedList(num,60);
	printLikedList(head);
	printLinkedListMax(head);
	printf("head data:%d",head->data);
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

void printLinkedListMax(node* head)
{
	node* ptr = head;
	int max = 0;
	while(ptr != NULL)
	{
		max = (max<ptr->data) ? ptr->data : max;
		ptr = ptr->next;
	}
	printf("the max of the linked list is:%d",max);
}
