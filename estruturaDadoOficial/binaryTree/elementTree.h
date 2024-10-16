#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_Show.h"

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

t_ElementTree 			        	 *elementTree_create(void *data,int sizeofData);
BOOL 						 ElementTree_Delete(t_ElementTree *elementTree);

void 	       				      *elementTree_Get_Data(t_ElementTree *elementTree);
int 	       				 elementTree_Get_SizeofData(t_ElementTree *elementTree);
t_ElementTree  		  	      *elementTree_Get_RightElement(t_ElementTree *elementTree);
t_ElementTree   		       *elementTree_Get_LeftElement(t_ElementTree *elementTree);


BOOL    elementTree_Add_RightElement(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd);
BOOL elementTree_Add_LeftElementTree(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd);

void 					 	   elementTree_Dump(t_ElementTree *elementTree);
//==============================================================================================
t_ElementTree 			        	  *elementTree_create(void *data,int sizeofData)
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
//==============================================================================================
BOOL 						  elementTree_Delete(t_ElementTree *elementTree)
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
//==============================================================================================
void 	       				       *elementTree_Get_Data(t_ElementTree *elementTree)
{
	
	if(elementTree==NULL)
	{
		return NULL;
	}	
	
	return elementTree->adressData;
}
//==============================================================================================
int 	       				  elementTree_Get_SizeofData(t_ElementTree *elementTree)
{	
	if(elementTree==NULL)
	{
		printf("elementTree igual a NULL\n");
		return 0;
	}
	return elementTree->sizeofData;
}
//==============================================================================================
t_ElementTree  			       *elementTree_Get_RightElement(t_ElementTree *elementTree)
{
	if(elementTree==NULL)
	{
		printf("elementTree igual a NULL\n");
		return NULL;
	}
	return elementTree->rightElementTree;
}
//==============================================================================================
t_ElementTree   		 	*elementTree_Get_LeftElement(t_ElementTree *elementTree)
{
	if(elementTree==NULL)
	{
		printf("elementTree igual a NULL\n");
		return NULL;
	}
	return elementTree->leftElementTree;
}
//==============================================================================================
BOOL     elementTree_Add_RightElement(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd)
{
	if(elementTree==NULL)
	{
		printf("elementTree igual a NULL\n");
		return FALSE;
	}
	if(elemetTreeToAdd==NULL)
	{
		printf("erro ao adicionar ao elemento direito\n");	
		return FALSE;
	}
	elementTree->rightElementTree=elemetTreeToAdd;
	return TRUE;
}
//==============================================================================================
BOOL  elementTree_Add_LeftElementTree(t_ElementTree *elementTree,t_ElementTree *elemetTreeToAdd)
{
	if(elementTree==NULL)
	{
		printf("elementTree igual a NULL\n");
		return FALSE;
	}
	if(elemetTreeToAdd==NULL)
	{
		printf("erro ao adicionar o eleemento esquerdoz\n");	
		return FALSE;
	}
	elementTree->leftElementTree=elemetTreeToAdd;
	return TRUE;
}
//==============================================================================================
void 						    elementTree_Dump(t_ElementTree *elementTree)
{
	if(elementTree==NULL)
	{
		printf("erro ao printar o elemento\n");
		return;
	}
	printf("DADO DO ELEMENTO:\n");
	if(elementTree_Get_Data(elementTree)==NULL)
	{
		printf("NULL\n");	
	}
	dataDump(elementTree_Get_Data(elementTree),elementTree_Get_SizeofData(elementTree));
	printf("DADO DO ELEMENTO DIREITO:\n");	
	if(elementTree_Get_Data(elementTree->rightElementTree)==NULL)
	{
		printf("NULL\n");	
	}else
	{
		dataDump(elementTree_Get_Data(elementTree->rightElementTree),elementTree_Get_SizeofData(elementTree));
	}

	printf("DADO DO ELEMENTO ESQUERDO:\n");	
	if(elementTree_Get_Data(elementTree->leftElementTree)==NULL)
	{
		printf("NULL\n");	
	}else
	{
	dataDump(elementTree_Get_Data(elementTree->leftElementTree),elementTree_Get_SizeofData(elementTree));
	}	
	printf("=================================================================\n");	
	return;
}
