
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "create.h"
#include "add.h"
#include "traverse.h"

/*
 * main
 */

int main( void ) {
  int i;
  Data *newData;
  Node *head, *newNode, *removed;

  // initialise an empty list
  head = NULL; 

  // create a linked list
  printf( "\nCreate a list of 5 items\n" );

  for( i=0; i<5; ++i ) {
    newData = createData( i, (float)i );
    newNode = createNode( newData ); 
    head = addNodeAtHead( head, newNode );
  }

  // traverse the list and print out the data
  printList( head );

  // insert a new node
  printf( "\nCreate a node and insert it\n" );

  newData = createData( -1, -2.0 );
  newNode = createNode( newData );
  insertNodeAfter( head->next, newNode );

  // traverse the list and print out the data
  printList( head );

  // delete a node following a given node
  printf( "\nDelete a node\n" );

  removed = deleteNextNode( head );
  freeNode( removed );

  // traverse the list and print out the data
  printList( head );

  // insert a new node at the head
  printf( "\nCreate a node and insert it at the head\n" );

  newData = createData( -3, -8.0 );
  newNode = createNode( newData );

  head = addNodeAtHead( head, newNode );

  // traverse the list and print out the data
  printList( head );

  // free the list data structure
  printf( "\nDelete the entire list\n" );

  head = freeListR( head ); // recursive implementation

  // traverse the list and print out the data
  printList( head );
  //testing adding a comment
  return 0;
}

