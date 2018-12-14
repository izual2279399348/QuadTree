#include "stdlib.h"
#include "math.h"
#include "stdio.h"
#include "writeTree.h"
#include "buildTree.h"
#include "treeStructure.h"
#include "task3.h"

/*To count the number*/
int node_added=0;
int node_removed=0;
int test_1=0;
int test_2=0;



int main( int argc, char **argv ) {
  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  //makeChildren( head );
  //makeChildren( head->child[1]->child[1] );
  growTree(head);
  growTree(head);
  growTree(head);
  //checkTree(head);
  //add_node(head);
  //remove_node(head);
  //add_node(head);
  adapt(head);
  // print the tree for Gnuplot
  printf("%d added,%d removed.",node_added,node_removed);
  writeTree( head );
  //destroyTree( head );
  return 0;
}
