
/*
 * structures
 */

typedef struct nodeData {
  int intData;
  float floatData;
} Data;

typedef struct node {
  Data *data;
  struct node *next;
} Node;

