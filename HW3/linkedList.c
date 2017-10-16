#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	// needed this or the compiler yelled at me
    return 0;
}

/* TO COMPILE:
Linux: gcc -shared -Wl,-soname,linkedList -o linkedList.so -fPIC add.c
Mac: gcc -shared -Wl,-install_name,linkedList.so -o linkedList.so -fPIC test.c
*/

/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList {
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
initList
param lst the linkedList
pre: lst is not null
post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	/* FIXME: you must write this */
	lst->firstLink = malloc(sizeof(struct DLink));
	lst->firstLink->next = NULL;
	lst->firstLink->prev = NULL;

	lst->lastLink = malloc(sizeof(struct DLink));
	lst->lastLink->prev = NULL;
	lst->lastLink->next = NULL;
}

/*
createList
param: none
pre: none
post: firstLink and lastLink reference sentinels
*/

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
_addLinkBeforeBefore
param: lst the linkedList
param: l the  link to add before
param: v the value to add
pre: lst is not null
pre: l is not null
post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	// increment the size
	lst->size++;

	// make new DLink
	struct DLink *newNode = malloc(sizeof(struct DLink));

	// set the newNode value to v
	newNode->value = v;

	// set the newNode next to the currentNode
	newNode->next = l;
	newNode->prev = l->prev;

	// if there's a current prev, set the next to newNode
	if (l->prev) {
		l->prev->next = newNode;
	}

	// set the currentNode prev to the newNode
	l->prev = newNode;
}

/*
_removeLink
param: lst the linkedList
param: l the linke to be removed
pre: lst is not null
pre: l is not null
post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{

	if (lst != NULL && l != NULL) {
		lst->size--;

		// if next, repoint next
		// if prev, repoint prev to next

		if (l->prev) {
			l->prev->next = l->next;
		}

		if (l->next) {
			l->next->prev = l->prev;
		}

		free(l);
	}

}

/*
isEmptyList
param: lst the linkedList
pre: lst is not null
post: none
*/
int isEmptyList(struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return(lst->size == 0);
}

/* De-allocate all links of the list

param: 	lst		pointer to the linked list
pre:	none
post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);
}

/* 	Deallocate all the links and the linked list itself.

param: 	v		pointer to the dynamic array
pre:	v is not null
post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
Pre: lst is not null
*/
void _printList(struct linkedList* lst)
{
	printf("\n==========\n");

	if (isEmptyList(lst)) {
		printf("List is empty");
	} else {

		printf("size: %d\n", lst->size);

		struct DLink *temporaryNodePointer = lst->firstLink;

		while (temporaryNodePointer) {
			printf("%d ", temporaryNodePointer->value);

			if (temporaryNodePointer->next) {
				temporaryNodePointer = temporaryNodePointer->next;
				printf(" -> ");
			} else {
				temporaryNodePointer = NULL;
			}
		}
	}

	printf("\n==========\n");
}

/* ************************************************************************
Deque Interface Functions
************************************************************************ */

/*
addFrontList
param: lst the linkedList
param: e the element to be added
pre: lst is not null
post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{

	// if there is no value
	if (isEmptyList(lst) || !lst->firstLink) {
		// increment the size
		lst->size++;

		// set the firstLink =  newNode
		lst->firstLink->value = e;

	} else {
		_addLinkBefore(lst, lst->firstLink, e);

		// update the firstLink
		lst->firstLink = lst->firstLink->prev;
		lst->firstLink->prev = NULL;
	}
}

/*
addBackList
param: lst the linkedList
param: e the element to be added
pre: lst is not null
post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {

	// increment the size
	lst->size++;

	if (isEmptyList(lst) || !lst->lastLink) {
		// set the firstLink =  newNode
		lst->lastLink->value = e;
	} else {
		struct DLink *newNode = malloc(sizeof(struct DLink));

		// point the new node's prev to the original node
		newNode->prev = lst->lastLink;
		newNode->next = NULL;
		newNode->value = e;

		// set the current lastLink->next to the newNode
		lst->lastLink->next = newNode;

		// finally, set the last node to the newNode
		lst->lastLink = newNode;

	}
}

/*
frontList
param: lst the linkedList
pre: lst is not null
pre: lst is not empty
post: none
*/
TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return(lst->firstLink->value);
}

/*
backList
param: lst the linkedList
pre: lst is not null
pre: lst is not empty
post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return(lst->lastLink->value);
}



/*
removeFrontList
param: lst the linkedList
pre:lst is not null
pre: lst is not empty
post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst)
{
	// do some checks
	lst->firstLink = lst->firstLink->next;
	lst->size--;
}

/*
removeBackList
param: lst the linkedList
pre: lst is not null
pre:lst is not empty
post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{
	printf("removing %d from back\n", lst->lastLink->value);

	lst->lastLink = lst->lastLink->prev;
	lst->size--;
}
