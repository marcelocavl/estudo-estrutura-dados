#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_Show.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;


typedef struct element{
	void   *data_Element;
	struct element *prox_Element;
	struct element *prev_Element;
	int    element_Size;
}t_Element;

t_Element *element_Create(void *data,int size);
void delete_Element(t_Element *element);
void *get_Data_Element(t_Element *element);

BOOL is_Null_Element(t_Element *element);
t_Element *get_Prox_Element(t_Element *element);
t_Element *get_Prev_Element(t_Element *element);
int get_Element_Size(t_Element *element);

t_Element *go_Next_Element(t_Element *element);
t_Element *go_Prev_Element(t_Element *element);

void dump_Element(t_Element *element);
/////////////////////////////////////////////////////////////////
t_Element *element_Create(void *data,int size){
	t_Element *new_Element;
	
	if((new_Element=malloc(sizeof(t_Element)))==NULL){
		printf("falha ao criar elemento\n");
		return NULL;
	}
	if((new_Element->data_Element=malloc(size))==NULL){
		printf("falha ao criar elemento\n");
		return NULL;
	}
	memcpy(new_Element->data_Element,data,size);
	new_Element->prox_Element=NULL;
	new_Element->prev_Element=NULL;
	new_Element->element_Size=size;
	printf("elemento criado com sucesso\n");
	return new_Element; 
}
/////////////////////////////////////////////////////////////////
void delete_Element(t_Element *element){
	free(element->data_Element);
	free(element);
	printf("elemento deletado\n");
	return;
}
/////////////////////////////////////////////////////////////////
BOOL is_Null_Element(t_Element *element){
	if(element==NULL){
		return TRUE;
	}
	return FALSE;
}


/////////////////////////////////////////////////////////////////
void *get_Data_Element(t_Element *element){
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	return element->data_Element;
	
}
/////////////////////////////////////////////////////////////////
t_Element *get_Prox_Element(t_Element *element){
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	return element->prox_Element;

}
/////////////////////////////////////////////////////////////////
t_Element *get_Prev_Element(t_Element *element){
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	return element->prev_Element;


}
/////////////////////////////////////////////////////////////////
int get_Element_Size(t_Element *element){
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return 0;
	}
	return element->element_Size;



}
/////////////////////////////////////////////////////////////////
void dump_Element(t_Element *element){
	if(is_Null_Element(element)){
		printf("falha ao printar elemento\n");
		return;
	}
	printf("ENDEREÇO ELEMENTO:\n");
	addressDump(element);
	printf("DADOS ELEMENTO\n");
	dataDump(get_Data_Element(element),get_Element_Size(element));
	printf("ENDEREÇO ELEMENTO ANTERIOR:\n");
	addressDump(get_Prev_Element(element));
	printf("ENDEREÇO ELEMENTO POSTERIOR:\n");
	addressDump(get_Prox_Element(element));
	printf("=====================================================================\n");
	return ;

}
/////////////////////////////////////////////////////////////////
t_Element *go_Next_Element(t_Element *element){
	element=element->prox_Element;
	return element;
}
/////////////////////////////////////////////////////////////////
t_Element *go_Prev_Element(t_Element *element){
	element=element->prev_Element;
	return element;
}
/////////////////////////////////////////////////////////////////


