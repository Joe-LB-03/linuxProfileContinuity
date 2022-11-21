#include <stdlib.h>

#include "linkedList.h"
#include "create.h"

/*
 * create node data
 */

Data *createData( int i, float f ) {

  Data *data = (Data *)malloc( sizeof(Data) );
  data->intData = i;
  data->floatData = f;

  return data;
}

/*
 * create a node
 */

Node *createNode( Data *data ) {

  Node *newNode = (Node *)malloc( sizeof(Node) );
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

/*
 * free a node 
 */

void freeNode( Node *node ) {

  free( node->data );
  free( node );
  
  return;
}

