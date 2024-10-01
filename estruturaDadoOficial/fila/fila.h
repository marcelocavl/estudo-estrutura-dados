#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "element.h"


#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;

typedef struct fila{
	t_Element *rootElement;
	t_Element *currentElement;
	int numElement;
}t_Fila;

t_Fila *fila_create();

BOOL fila_Is_Root_Element_Null(t_Fila *fila);
BOOL fila_Is_Current_Element_Null(t_Fila *fila);
BOOL fila_Is_Num_Element_Zero(t_Fila *fila);

t_Element *fila_Get_Root_Element(t_Fila *fila);
t_Element *fila_Get_Current_Element(t_Fila *fila);
int fila_Get_Num_Element(t_Fila *fila);

void fila_Go_Prox_Element(t_Fila *fila);
void fila_Go_Prev_Element(t_Fila *fila);
void fila_Go_Last_Element(t_Fila *fila);
void fila_Go_To_Root_Element(t_Fila *fila);
void fila_Go_Penultimate_Element(t_Fila *fila);


void fila_Alocate_Element(t_Fila *fila,void *data,int sizeData);
void fila_Desalocate_Element(t_Fila *fila);

void fila_Dump(t_Fila *fila);

/////////////////////////////////////////////////////////////////
t_Fila *fila_create(){
	t_Fila *new_Fila;
	if((new_Fila=malloc(sizeof(t_Fila)))==NULL){
		printf("falha ao alocar fila\n");
		return NULL;
	}
	new_Fila->rootElement=NULL;
	new_Fila->currentElement=new_Fila->rootElement;
	new_Fila->numElement=0;
printf("Fila criada com sucesso\n");
	return new_Fila;
	
}
/////////////////////////////////////////////////////////////////
BOOL fila_Is_Root_Element_Null(t_Fila *fila){
	if(fila->rootElement==NULL){
		return TRUE;
	}
		return FALSE;
}
/////////////////////////////////////////////////////////////////
BOOL fila_Is_Current_Element_Null(t_Fila *fila){
		if(fila->currentElement==NULL){
		return TRUE;
	}
		return FALSE;

}
/////////////////////////////////////////////////////////////////
BOOL fila_Is_Num_Element_Zero(t_Fila *fila){
		if(fila->numElement==0){
		return TRUE;
	}
		return FALSE;
}
/////////////////////////////////////////////////////////////////
t_Element *fila_Get_Root_Element(t_Fila *fila){
	if(fila_Is_Root_Element_Null(fila)){
		printf("Elemento root é NULL\n");
		return NULL;
	}
	return fila->rootElement;
}
/////////////////////////////////////////////////////////////////
t_Element *fila_Get_Current_Element(t_Fila *fila){
	if(fila_Is_Current_Element_Null(fila)){
		printf("Elemento current  é NULL\n");
		return NULL;
	}
	return fila->currentElement;
}
/////////////////////////////////////////////////////////////////
int fila_Get_Num_Element(t_Fila *fila){
	if(fila_Is_Num_Element_Zero(fila)){
		printf("numero de elementos é igual a ZERO\n");
		return 0;
	}
		return fila->numElement;
}
/////////////////////////////////////////////////////////////////
void fila_Go_Prox_Element(t_Fila *fila){
	fila->currentElement=get_Prox_Element(fila_Get_Current_Element(fila));
	return;
}
/////////////////////////////////////////////////////////////////
void fila_Go_Prev_Element(t_Fila *fila){
	fila->currentElement=get_Prev_Element(fila_Get_Current_Element(fila));
	return;
}
/////////////////////////////////////////////////////////////////
void fila_Go_Last_Element(t_Fila *fila){
	if(fila_Is_Num_Element_Zero(fila)){
		printf("fila esta vazia\n");
		return;
	}
	fila_Go_To_Root_Element(fila);
	int i;
	for(i=1;i<fila_Get_Num_Element(fila);i++){
		fila_Go_Prox_Element(fila);
	}
	return;
}
/////////////////////////////////////////////////////////////////
void fila_Go_Penultimate_Element(t_Fila *fila){
	fila_Go_Last_Element(fila);
	fila_Go_Prev_Element(fila);
}
/////////////////////////////////////////////////////////////////
void fila_Go_To_Root_Element(t_Fila *fila){
	fila->currentElement=fila->rootElement;
	return;
}
/////////////////////////////////////////////////////////////////
void fila_Alocate_Element(t_Fila *fila,void *data,int sizeData){
	if(data==NULL){
		printf("elemento NULL\n");	
		return;

	}

	if(fila==NULL){
		printf("fila NULL\n");	
		return;

	}
	if(fila_Is_Num_Element_Zero(fila)){
		fila->rootElement=element_Create(data,sizeData);
		(fila->numElement)++;
		printf("elemento alocado com sucesso\n");
		return;
	}
	fila_Go_Last_Element(fila);
	t_Element *current=fila_Get_Current_Element(fila);
	current->prox_Element=element_Create(data,sizeData);
	current->prox_Element->prev_Element=current;
	(fila->numElement)++;
	printf("elemento alocado com sucesso\n");
	return;
}
/////////////////////////////////////////////////////////////////
void fila_Desalocate_Element(t_Fila *fila){
	fila_Go_To_Root_Element(fila);
	fila_Go_Prox_Element(fila);
	fila->rootElement=fila_Get_Current_Element(fila);
	t_Element *rootElement=fila_Get_Current_Element(fila);
	rootElement->prev_Element=NULL;
	fila->numElement--;
	return;

}
/////////////////////////////////////////////////////////////////
void fila_Dump(t_Fila *fila){
	printf("==========================================\n");
	int i;
	fila_Go_To_Root_Element(fila);
	for(i=0;i<fila_Get_Num_Element(fila);i++){
		dump_Element(fila_Get_Current_Element(fila));
		fila_Go_Prox_Element(fila);
	}
	return;
}

