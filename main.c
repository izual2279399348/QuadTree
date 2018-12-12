#include "math.h"
#include "stdio.h"
#include "writeTree.h"
#include "buildTree.h"
#include "treeStructure.h"
int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  //makeChildren( head );
  //makeChildren( head->child[1] );
  growTree(head);
  //growTree(head);
  makeChildren( head->child[1] );
  makeChildren( head->child[2] );
  // print the tree for Gnuplot
  writeTree( head );
  removeChildren( head->child[1] );
  //removeChildren( head );
  destroyTree( head );
  return 0;
}
