#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "elementTree.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;


typedef struct binaryTree
{
	t_ElementTree *rootElement;
	int 	       numElements;
}t_BinaryTree;

t_BinaryTree *binaryTree_Create();
void binaryTree_Delete(t_BinaryTree *binaryTree);

void binaryTree_Add(t_BinaryTree *binaryTree,void *data);
void binaryTree_Remove(t_BinaryTree *binaryTree,void *data);

//==============================================================================================
t_BinaryTree *binaryTree_Create()
{
	t_BinaryTree *newBinaryTree;
	if((newBinaryTree=malloc(sizeof(t_BinaryTree)))
	{
		printf("erro ao criar a binaryTree\n");
		return NULL;
	}
	newBinaryTree->rootElement=NULL;
	newBinaryTree->numElements=0;
	return newBinaryTree;
}
//==============================================================================================
void binaryTree_Delete(t_BinaryTree *binaryTree);
//==============================================================================================
void binaryTree_Add(t_ElementTree *rootElement,void *data,int sizeofData)
{
	if(rootElement==NULL)
	{
		printf("root element igual a NULL\n");
		return;
	}	
	if(data==NULL)
	{
		printf("data igual a NULL");
		return;
	}	
	t_ElementTree *element=elementTree_create(data,sizeofData);
	if(element==NULL)
	{
		printf("erro ao alocar elemento\n" );
		return;
	}
	
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))>0 && (elementTree_Get_RightElement(rootElement))==NULL)
	{
		rootElement->rightElementTree=element;
		return;
	}
	
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))<0 && (elementTree_Get_LeftElement(rootElement))==NULL)

	{
		rootElement->rightElementTree=element;
		return;
	}
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))>0)
	{	
		binaryTree_Add(elementTree_Get_RightElement(rootElement),data,sizeofData);	
	}
	
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))>0)
	{	
		binaryTree_Add(elementTree_Get_RightElement(rootElement),data,sizeofData);	
	}
	return;




}
//==============================================================================================
void binaryTree_Remove(t_BinaryTree *binaryTree,void *data);
//==============================================================================================
void binaryTree_Dump(t_BinaryTree *binaryTree);
//==============================================================================================
