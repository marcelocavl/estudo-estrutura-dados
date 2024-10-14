#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elementTree
{
	void *data;
	struct elementTree *proxElemn
}

void 			        elementTree_create(void *data);
void 		ElementTree_Delete(t_ElementTree *elementTree);

void 	       				      elementTree_Get_Data(t_ElementTree *ElementTree);
void  				      elementTree_Get_RightElement(t_ElementTree *ElementTree);
void   				       elementTree_Get_LeftElement(t_ElementTree *ElementTree);

void    elementTree_Add_RightElement(t_ElementTree *elementTree,t_ElementTree elemetTreeToAdd);
void elementTree_Add_LeftElementTree(t_ElementTree *elementTree,t_ElementTree elemetTreeToAdd);
