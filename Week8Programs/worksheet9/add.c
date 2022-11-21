#include <stdlib.h>
#include "linkedList.h"
#include "add.h"

/*
 * add a node to the list at the head
 */

Node *addNodeAtHead( Node *head, Node *newNode ) {

  newNode->next = head;

  return newNode;
}

/*
 * add a node to the list at the tail
 */

Node *addNodeAtTail( Node *head, Node *newNode )
{
	newNode->next = NULL;
	Node *last = head;

	if(head == NULL)
	{
		head = newNode;
		return head;
	}
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = newNode;
    return head;
} 

/*
 * insert a node after a given location
 */

void insertNodeAfter( Node *location, Node *new ) {

  new->next = location->next;
  location->next = new;

  return;
}

/*
 * delete a node from the list
 */

Node *deleteNextNode( Node *location ) {

  Node *toBeRemoved = location->next;
  location->next = toBeRemoved->next;  // unlink from the list

  return toBeRemoved;
}

