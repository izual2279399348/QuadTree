#include"treeStructure.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"
#include "task3.h"
#include "buildTree.h"

extern int node_removed;
extern int node_added;
extern int test_1;
extern int test_2;
/*To give these nodes flag values */

void checkTree(Node *thenode){
    if(thenode->child[0]==NULL){
        if(nodeValue(thenode,0.0)>0.5){
            thenode->flag=1;
        }
        else if(nodeValue(thenode,0.0)<-0.5){
            thenode->flag=-1;
        }
    }
    else{
        thenode->flag=0;
        for(int i=0;i<4;i++){
            checkTree(thenode->child[i]);
        }
    }

}

/* To add the nodes which flag equal to 1*/
void add_node(Node *thenode){
    if(thenode->child[0]==NULL){
        if(thenode->flag==1&&thenode->level<6){
            makeChildren( thenode );
            node_added+=4;
        }
        else{
            return;
        }
    }
    else{
        for(int i=0;i<4;i++){
            add_node(thenode->child[i]);
        }
    }
    return;
}
/*To remove the Children of a parent node that has all children which flag is equal to -1*/

void remove_node(Node *the_node){
    int a=1;
    if(the_node->child[0]==NULL){
        return;
    }
    else if(the_node->flag==0){
        for(int i=0;i<4;i++){
            if(the_node->child[i]->flag==-1){
            }
            else{
                a=0;
            }
        }
        if(a==1){
            removeChildren( the_node );
            node_removed+=4;
        }
        else{
            for(int i=0;i<4;i++){
                remove_node(the_node->child[i]);
            }
        }
    }
}
/*To automaticly add and remove the node*/
void adapt( Node *head ){
    int count_;
    count_=0;
    while(1){
        test_1=node_added;
        test_2=node_removed;
        checkTree(head);
        add_node(head);
        remove_node(head);
        test_1=node_added-test_1;
        test_2=node_removed-test_2;
        if(test_1==0&&test_2==0&&count_!=0){
            break;
        }
        count_++;
    }
}
