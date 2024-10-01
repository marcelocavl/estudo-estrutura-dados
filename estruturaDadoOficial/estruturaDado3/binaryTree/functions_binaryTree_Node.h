#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions_Show.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;



////////////////////////////////////////////////////
void   *create_Node(void *data,int size);
void 		 delete_Node(void *data);
//funcoes alocar left right
void 	      allocate_Right(void *node,void *dadNode);
void           allocate_left(void *node,void *dadNode);	
void 		    dumpNode(void *node);

////////////////////////////////////////////////////
//funcoes find
BOOL find_Node(void *node,void *data);



void   *create_Node(void *data,int size){
	typedef struct node{
		void  *data;
		int    size;
		void  *left;
		void *right;
	}node;
	
	node *newNode;
	if((newNode=malloc(sizeof(node)))==NULL || (newNode->data=malloc(sizeof(size)))==NULL){
		printf("FALHA AO ALOCAR NÓ");
		return NULL;
	}
	memcpy(newNode->data,data,size);
	newNode->size=size;
	newNode->left=NULL;
	newNode->right=NULL;
	printf("nó alocado com sucesso!\n");	 
	return newNode;

}
/////////////////////////////////////////////////
void 	delete_Node(void *node){
	void *data_node;
	data_node=(int *)(*(long int *)node);
	free(data_node);
	free(node);
	printf("no desalocado!\n");
}
/////////////////////////////////////////////////
void 	      allocate_Right(void *node,void *dadNode){
	*(long int *)(dadNode+24)=*(long int *)(&node);
	
}


void           allocate_left(void *node,void *dadNode){
	*(long int *)(dadNode+16)=*(long int *)(&node);

}
void dumpNode(void *node){
printf("-----------------------------------------------\n");
	printf("valor : \n");
	dataDump(((int *)(*(long int *)(node))),4);

	if((long int *)(*(long int *)(node+16))==NULL){
		printf("endereço esquerdo\n");
		printf("NULL\n"); 
	}else{
		printf("endereço esquerdo:\n");
		addressDump((int *)(*(long int *)(node+16)));
	}
	
	if((long int *)(*(long int *)(node+24))==NULL){
		printf("endereço direito:\n");
		printf("NULL\n"); 
	}else{
		printf("endereço direito:\n");
		addressDump((int *)(*(long int *)(node+24)));
	}

printf("-----------------------------------------------\n");




}
///////////////////////////////////////////////////////////////q
///
///
 
BOOL find_Node(void *node,void *data){
	void *data_Node;
	*(long int *)(&data_Node)=*(long int *)(node);
	if((memcmp(data_Node,data,4))==0){
		printf("ta aqui o!\n"); 
		return TRUE;
		
	}else{

		return FALSE;
	}






}
