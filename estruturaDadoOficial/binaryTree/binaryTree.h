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

t_BinaryTree *binaryTree_Create(void *rootValue,int rootSize);
void binaryTree_Delete(t_BinaryTree *binaryTree);

BOOL binaryTree_Is_leaf(t_ElementTree *elementTree);
	
t_ElementTree *binaryTree_Get_RootElement(t_BinaryTree *binaryTree);
void binaryTree_Get_NumElements(t_BinaryTree *binaryTree);

void binaryTree_Add(t_BinaryTree *binaryTree,t_ElementTree *rootElement,void *data,int sizeofData);
void binaryTree_Remove(t_BinaryTree *binaryTree,void *data);

//==============================================================================================
t_BinaryTree *binaryTree_Create(void *rootValue,int rootSize)
{
	t_BinaryTree *newBinaryTree;
	if((newBinaryTree=malloc(sizeof(t_BinaryTree)))==NULL)
	{
		printf("erro ao criar a binaryTree\n");
		return NULL;
	}
	if((newBinaryTree->rootElement=elementTree_create(rootValue,rootSize))==NULL)
	{
		printf("erro ao criar a binaryTree\n");
		return NULL;
	}
	newBinaryTree->numElements=1;
	printf("sucesso ao criar binary tree\n");	
	return newBinaryTree;
}
//==============================================================================================
void binaryTree_Delete(t_BinaryTree *binaryTree);
//==============================================================================================
BOOL binaryTree_Is_leaf(t_ElementTree *elementTree)
{
	if(elementTree==NULL){
		printf("elemento igual a NULL\n");	
		return FALSE;
	}
	if(elementTree->rightElementTree==NULL && elementTree->leftElementTree==NULL){
		return TRUE;		
	}
	return FALSE;
}
//==============================================================================================
t_ElementTree *binaryTree_Get_RootElement(t_BinaryTree *binaryTree)
{

	if(binaryTree=NULL)
	{
		printf("binaryTree igual a NULL\n");	
		return NULL;
	}
	if(binaryTree->rootElement==NULL)
	{
		printf("root element iguaL a NULL\n");	
		return NULL;
	}
	return binaryTree->rootElement;

}
//==============================================================================================
void binaryTree_Get_NumElements(t_BinaryTree *binaryTree);
//==============================================================================================
void binaryTree_Add(t_BinaryTree *binaryTree,t_ElementTree *rootElement,void *data,int sizeofData)
{

	printf("entrei aqui\n");
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
		binaryTree->numElements++;
		return;
	}
	
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))<0 && (elementTree_Get_LeftElement(rootElement))==NULL)

	{
		rootElement->leftElementTree=element;
		binaryTree->numElements++;
		return;
	}
	if((memcmp(elementTree_Get_Data(element),elementTree_Get_Data(rootElement),elementTree_Get_SizeofData(element)))>0)
	{	
		binaryTree_Add(binaryTree,elementTree_Get_RightElement(rootElement),data,sizeofData);	
	}
	
	if((memcmp(elementTree_Get_Data(element),(elementTree_Get_Data(rootElement)),elementTree_Get_SizeofData(element)))<0)
	{	
		binaryTree_Add(binaryTree,elementTree_Get_LeftElement(rootElement),data,sizeofData);	
	}
	return;


}
//==============================================================================================
void binaryTree_Remove(t_BinaryTree *binaryTree,void *data);
//==============================================================================================
void binaryTree_Dump(t_BinaryTree *binaryTree,t_ElementTree *rootElement)
{
	if(binaryTree==NULL){
		printf("erro ao printar árvore\n");		
		return;
	}
	if(binaryTree_Is_leaf(rootElement)){
		elementTree_Dump(rootElement);
		return;
	}
	elementTree_Dump(rootElement);
	if(rootElement->rightElementTree!=NULL){
		binaryTree_Dump(binaryTree,rootElement->rightElementTree);
	}
	if(rootElement->leftElementTree!=NULL){
		binaryTree_Dump(binaryTree,rootElement->leftElementTree);
	}
	return;
}
//==============================================================================================
