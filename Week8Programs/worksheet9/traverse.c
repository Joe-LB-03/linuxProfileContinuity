#include <stdio.h>

#include "linkedList.h"
#include "create.h"
#include "traverse.h"

/*
 * traverse the list and print out the data
 */

void printList( Node *head ) {

  Node *location = head;

  printf( "\n Current list\n" );
  while( location != NULL ) {
    printf(" %i %f \n", location->data->intData, location->data->floatData ); 
    location = location->next;
  }
  return;
}

/*
 * traverse the list and free all the memory
 */

Node *freeList( Node *head ) {

  Node *location = head;

  while( location != NULL ) {
    
    Node *next = location->next; // store the next location
    freeNode( location );  // free the current node
    location = next;       // next node
  }
  return NULL;
}

/*
 * traverse the list and free all the memory - recursive
 */

Node *freeListR( Node *location ) {

  if( location != NULL ) { // exit condition - location==NULL

    Node *next = location->next; // store the next location
    freeNode( location );  // free the current node
    freeListR( next );     // recursive call
  }
  return NULL;
}

