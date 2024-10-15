#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  TRUE 1
#define FALSE 0
typedef unsigned char BOOL;

typedef struct elementTree
{
	void  		       	 *adressData;
	int                       sizeofData;
	struct elementTree *rightElementTree;
	struct elementTree  *leftElementTree;
}t_ElementTree;

t_ElementTree 			        			       *elementTree_create(void *data,int sizeofData);
BOOL 							ElementTree_Delete(t_ElementTree *elementTree);

void 	       				      	     *elementTree_Get_Data(t_ElementTree *ElementTree);
void  				             *elementTree_Get_RightElement(t_ElementTree *ElementTree);
void   				       	      *elementTree_Get_LeftElement(t_ElementTree *ElementTree);

BOOL    	elementTree_Add_RightElement(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd);
BOOL	     elementTree_Add_LeftElementTree(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd);
//=====================================================================================================
t_ElementTree 			        				*elementTree_create(void *data,int sizeofData)
{
	t_ElementTree *newElement;
	
	if(data==NULL)
	{
		printf("erro ao criar elemento!\n");
		return NULL;
	}
	
	if((newElement=malloc(sizeof(t_ElementTree)))==NULL)
	{
		printf("erro ao criar elemento!\n");
		return NULL;
	}
	if((newElement->adressData=malloc(sizeof(data)))==NULL)
	{
		printf("erro ao criar elemento!\n");
		return NULL;
	}
	memcpy(newElement->adressData,data,sizeof(data));
	newElement->sizeofData=sizeofData;
	newElement->rightElementTree=NULL;
	newElement->leftElementTree=NULL;
	printf("elemento criado\n");	
	return newElement;
}
//=====================================================================================================
BOOL 							elementTree_Delete(t_ElementTree *elementTree)
{
	if(elementTree==NULL)
	{
		printf("erro ao deletar elemento\n");
		return FALSE;
	}
	
	free(elementTree->adressData);
	free(elementTree);
	printf("elemento deletado\n");
	return TRUE;
}
//=====================================================================================================
void 	       				      	     *elementTree_Get_Data(t_ElementTree *ElementTree)
{
	return ElementTree->adressData;
}
//=====================================================================================================
void  				             *elementTree_Get_RightElement(t_ElementTree *ElementTree)
{
	return ElementTree->rightElementTree;
}
//=====================================================================================================
void   				       	      *elementTree_Get_LeftElement(t_ElementTree *ElementTree)
{
	return ElementTree->leftElementTree;
}
//=====================================================================================================
BOOL    	elementTree_Add_RightElement(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd)
{
	if(elemetTreeToAdd==NULL)
	{
		printf("erro ao adicionar ao elemento direito\n");	
		return FALSE;
	}
	elementTree->rightElementTree=elemetTreeToAdd;
	return TRUE;
}
//=====================================================================================================
BOOL	     elementTree_Add_LeftElementTree(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd)
{
	if(elemetTreeToAdd==NULL)
	{
		printf("erro ao adicionar o eleemento esquerdoz\n");	
		return FALSE;
	}
	elementTree->leftElementTree=elemetTreeToAdd;
	return TRUE;
}
