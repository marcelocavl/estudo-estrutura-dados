#include<stdio.h>#include<stdlib.h>
#include<string.h>
#include "element.h"

#define TRUE  1
#define FALSE 0

typedef struct lista{
	void *root_Element;
	void *current_Element;
	int num_Elements;
}t_Lista;

t_Lista *list_Create();

BOOL list_Is_Null_Root_Element(t_Lista *list);
BOOL list_Is_Null_Current_Element(t_Lista *list);
BOOL list_Is_Zero_Num_Elements(t_Lista *list);


t_Element *list_get_Root_Element(t_Lista *list);
t_Element *list_get_Current_Element(t_Lista *list);
t_Element *list_get_This_Element(t_Lista *list,void *data);
int list_get_Num_Elements(t_Lista *list);


void list_Go_Next_Element(t_Lista *list);
void list_Go_Prev_Element(t_Lista *list);
void list_Go_To_Root(t_Lista *list);
void list_Go_To_Last(t_Lista *list);

void list_Alocate_Element(t_Lista *list,void *data,int sizeData);
void list_Desalocate_Element(t_Lista *list,void *data);

void list_Dump_List(t_Lista *list);

/////////////////////////////////////////////////////////////////
t_Lista *list_Create(){
	t_Lista *new_Lista;
	if((new_Lista=malloc(sizeof(t_Lista)))==NULL){
		printf("falha ao criar lista");
		return NULL;
	}
	new_Lista->root_Element=NULL;
	new_Lista->current_Element=new_Lista->root_Element;
	new_Lista->num_Elements=0;
	printf("lista criada com sucesso\n");
	return new_Lista;

}
/////////////////////////////////////////////////////////////////
BOOL list_Is_Null_Root_Element(t_Lista *list){
	if(list->root_Element==NULL){
		return TRUE;
	}
	return FALSE;


}
/////////////////////////////////////////////////////////////////
BOOL list_Is_Null_Current_Element(t_Lista *list){
	if(list->current_Element==NULL){
		return TRUE;
	}
	return FALSE;
}
/////////////////////////////////////////////////////////////////
BOOL list_Is_Zero_Num_Elements(t_Lista *list){
	if(list->num_Elements==0){
		return TRUE;
	}
	return FALSE;
}	
/////////////////////////////////////////////////////////////////
t_Element *list_get_Root_Element(t_Lista *list){
	if(list_Is_Null_Root_Element(list)){
		printf("root element igual a NULL\n");	
		return NULL;	
	}
	return list->root_Element;
}
/////////////////////////////////////////////////////////////////
t_Element *list_get_Current_Element(t_Lista *list){
	if(list_Is_Null_Current_Element(list)){
		printf("current element igual a NULL\n");	
		return NULL;	
	}
	return list->current_Element;
}
/////////////////////////////////////////////////////////////////
int list_get_Num_Elements(t_Lista *list){
	if(list_Is_Zero_Num_Elements(list)){
		return  0;	
	}
	return list->num_Elements;
}
/////////////////////////////////////////////////////////////////

t_Element *list_get_This_Element(t_Lista *list,void *data){
	if(list_Is_Zero_Num_Elements(list)){
		printf("lista vazia \n");
		return NULL;
	}
	int i;
	list_Go_To_Root(list);
	for(i=0;i<list_get_Num_Elements(list);i++){
		if(!(memcmp(get_Data_Element(list_get_Current_Element(list)),data,get_Element_Size(list_get_Current_Element(list))))){
			return list_get_Current_Element(list);
		}
		list_Go_Next_Element(list);
	}
}

/////////////////////////////////////////////////////////////////
void list_Go_Next_Element(t_Lista *list){
	list->current_Element=get_Prox_Element(list_get_Current_Element(list));
	return;
}
/////////////////////////////////////////////////////////////////
void list_Go_Prev_Element(t_Lista *list){
	list->current_Element=get_Prev_Element(list_get_Current_Element(list));
	return;
}
/////////////////////////////////////////////////////////////////
void list_Go_To_Root(t_Lista *list){
	list->current_Element=list_get_Root_Element(list);
	return;
}
/////////////////////////////////////////////////////////////////
void list_Go_To_Last(t_Lista *list){
	list_Go_To_Root(list);
	int i;
	for(i=0;i<list_get_Num_Elements(list);i++){
		if((get_Prox_Element(list_get_Current_Element(list)))==NULL){
			break;
		}
		list_Go_Next_Element(list);
	}
	return;
}
/////////////////////////////////////////////////////////////////

void list_Alocate_Element(t_Lista *list,void *data,int sizeData){
	if(data==NULL){
		printf("não pode elemento NULL\n");
		return;
	}
	if(list_Is_Zero_Num_Elements(list)){
		list->root_Element=element_Create(data,sizeData);
		(list->num_Elements)++;
		printf("elemento alocado com sucesso\n");
		return;
	}
	list_Go_To_Last(list);
	t_Element *current=list_get_Current_Element(list);
	current->prox_Element=element_Create(data,sizeData);
	current->prox_Element->prev_Element=current;
	//(list->current_Element)->prox_Element=element_Create(data,sizeData);
	(list->num_Elements)++;
	printf("elemento alocado com sucesso\n");
	return;
}
/////////////////////////////////////////////////////////////////
void list_Desalocate_Element(t_Lista *list,void *data){
	list->current_Element=list_get_This_Element(list,data);
	t_Element *temp=list_get_Current_Element(list);
	list_Go_Prev_Element(list);
	t_Element *temp2=list_get_Current_Element(list);
	temp2->prox_Element=temp->prox_Element;
	delete_Element(temp);
	return;
	
}
/////////////////////////////////////////////////////////////////
void list_Dump_List(t_Lista *list){
	if(list_Is_Zero_Num_Elements(list)){
		printf("lista vazia\n");
		return;
	}
	int i;
printf("aqui \n");
	list_Go_To_Root(list);
	for(i=0;i<list_get_Num_Elements(list);i++){
		dump_Element(list_get_Current_Element(list));
		list_Go_Next_Element(list);
		
	}
	return;
}


