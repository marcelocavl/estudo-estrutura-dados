#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "binaryTree.h"


int main()
{
	int x=12;
	t_BinaryTree *binaryTree=binaryTree_Create(&x,sizeof(int));
	int y=13;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&y,sizeof(int));
	int z=10;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&z,sizeof(int));
	int j=11;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=14;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=8;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=9;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=15;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	
	j=15;
	
	binaryTree_Remove_Node(binaryTree,&j);
	binaryTree_Dump(binaryTree,binaryTree->rootElement);
		

}

