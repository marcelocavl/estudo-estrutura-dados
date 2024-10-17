#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "element.h"


#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;

typedef struct pilha{
	t_Element *rootElement;
	t_Element *currentElement;
	int numElement;
}t_Pilha;

t_Pilha *pilha_create();

BOOL pilha_Is_Root_Element_Null(t_Pilha *pilha);
BOOL pilha_Is_Current_Element_Null(t_Pilha *pilha);
BOOL pilha_Is_Num_Element_Zero(t_Pilha *pilha);

t_Element *pilha_Get_Root_Element(t_Pilha *pilha);
t_Element *pilha_Get_Current_Element(t_Pilha *pilha);
int pilha_Get_Num_Element(t_Pilha *pilha);

void pilha_Go_Prox_Element(t_Pilha *pilha);
void pilha_Go_Prev_Element(t_Pilha *pilha);
void pilha_Go_Last_Element(t_Pilha *pilha);
void pilha_Go_To_Root_Element(t_Pilha *pilha);
void pilha_Go_Penultimate_Element(t_Pilha *pilha);

void pilha_Alocate_Element(t_Pilha *pilha,void *data,int sizeData);
void pilha_Desalocate_Element(t_Pilha *pilha);

void pilha_Dump(t_Pilha *pilha);

/////////////////////////////////////////////////////////////////
t_Pilha *pilha_create(){
	t_Pilha *new_Pilha;
	if((new_Pilha=malloc(sizeof(t_Pilha)))==NULL){
		printf("falha ao alocar pilha\n");
		return NULL;
	}
	new_Pilha->rootElement=NULL;
	new_Pilha->currentElement=new_Pilha->rootElement;
	new_Pilha->numElement=0;
printf("pilha criada com sucesso\n");
	return new_Pilha;
	
}
/////////////////////////////////////////////////////////////////
BOOL pilha_Is_Root_Element_Null(t_Pilha *pilha){
	if(pilha->rootElement==NULL){
		return TRUE;
	}
		return FALSE;
}
/////////////////////////////////////////////////////////////////
BOOL pilha_Is_Current_Element_Null(t_Pilha *pilha){
		if(pilha->currentElement==NULL){
		return TRUE;
	}
		return FALSE;

}
/////////////////////////////////////////////////////////////////
BOOL pilha_Is_Num_Element_Zero(t_Pilha *pilha){
		if(pilha->numElement==0){
		return TRUE;
	}
		return FALSE;
}
/////////////////////////////////////////////////////////////////
t_Element *pilha_Get_Root_Element(t_Pilha *pilha){
	if(pilha_Is_Root_Element_Null(pilha)){
		printf("Elemento root é NULL\n");
		return NULL;
	}
	return pilha->rootElement;
}
/////////////////////////////////////////////////////////////////
t_Element *pilha_Get_Current_Element(t_Pilha *pilha){
	if(pilha_Is_Current_Element_Null(pilha)){
		printf("Elemento current  é NULL\n");
		return NULL;
	}
	return pilha->currentElement;
}
/////////////////////////////////////////////////////////////////
int pilha_Get_Num_Element(t_Pilha *pilha){
	if(pilha_Is_Num_Element_Zero(pilha)){
		printf("numero de elementos é igual a ZERO\n");
		return 0;
	}
		return pilha->numElement;
}
/////////////////////////////////////////////////////////////////
void pilha_Go_Prox_Element(t_Pilha *pilha){
	pilha->currentElement=get_Prox_Element(pilha_Get_Current_Element(pilha));
	return;
}
/////////////////////////////////////////////////////////////////
void pilha_Go_Prev_Element(t_Pilha *pilha){
	pilha->currentElement=get_Prev_Element(pilha_Get_Current_Element(pilha));
	return;
}
/////////////////////////////////////////////////////////////////
void pilha_Go_Last_Element(t_Pilha *pilha){
	if(pilha_Is_Num_Element_Zero(pilha)){
		printf("pilha esta vazia\n");
		return;
	}
	pilha_Go_To_Root_Element(pilha);
	int i;
	for(i=1;i<pilha_Get_Num_Element(pilha);i++){
		pilha_Go_Prox_Element(pilha);
	}
	return;
}
/////////////////////////////////////////////////////////////////
void pilha_Go_Penultimate_Element(t_Pilha *pilha){
	pilha_Go_Last_Element(pilha);
	pilha_Go_Prev_Element(pilha);
}
/////////////////////////////////////////////////////////////////
void pilha_Go_To_Root_Element(t_Pilha *pilha){
	pilha->currentElement=pilha->rootElement;
	return;
}
/////////////////////////////////////////////////////////////////
void pilha_Alocate_Element(t_Pilha *pilha,void *data,int sizeData){
	if(data==NULL){
		printf("elemento NULL\n");	
		return;

	}

	if(pilha==NULL){
		printf("pilha NULL\n");	
		return;

	}
	if(pilha_Is_Num_Element_Zero(pilha)){
		pilha->rootElement=element_Create(data,sizeData);
		(pilha->numElement)++;
		return;
	}
	pilha_Go_Last_Element(pilha);
	t_Element *current=pilha_Get_Current_Element(pilha);
	current->prox_Element=element_Create(data,sizeData);
	current->prox_Element->prev_Element=current;
	(pilha->numElement)++;
	printf("elemento alocado com sucesso\n");
	return;
}
/////////////////////////////////////////////////////////////////
void pilha_Desalocate_Element(t_Pilha *pilha){
	if(pilha_Is_Num_Element_Zero(pilha)){
		printf("não há elementos para deletar, pilha vazia!\n");
		return;
	}
	pilha_Go_Penultimate_Element(pilha);
	t_Element *current=pilha_Get_Current_Element(pilha);
	delete_Element(go_Next_Element(current));
	current->prox_Element=NULL;	
	pilha->numElement--;
	return ;
}
/////////////////////////////////////////////////////////////////
void pilha_Dump(t_Pilha *pilha){
	int i;
	pilha_Go_To_Root_Element(pilha);
	for(i=0;i<pilha_Get_Num_Element(pilha);i++){
		dump_Element(pilha_Get_Current_Element(pilha));
		pilha_Go_Prox_Element(pilha);
	}
	return;
}

