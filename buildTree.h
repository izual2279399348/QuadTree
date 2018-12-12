#include "treeStructure.h"
#ifndef BUILDTREE_H
#define BUILDTREE_H
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree( Node *parent );
#endif
