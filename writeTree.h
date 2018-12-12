#include "stdlib.h"
#include "treeStructure.h"
#ifndef WRITETREE_H
#define WRITETREE_H
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
// write out the (x,y) corners of the node
void destroyTree( Node *the_node );
void printOut( FILE *fp, Node *node );
#endif
