#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pilha.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;
//FUNCOES PACIENTE
/*
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
*/
typedef struct paciente{
	int id;
}t_Paciente;

t_Paciente *paciente_Create(int id);
void paciente_Dump(t_Paciente paciente);


///////////////////////////////////////////////////////////////
t_Paciente *paciente_Create(int id){
	t_Paciente *newPaciente=malloc(sizeof(t_Paciente));
	newPaciente->id=id;
	return newPaciente;
}
///////////////////////////////////////////////////////////////
void paciente_Dump(t_Paciente paciente){
	printf("id do paciente:\n");	
	printf("%d\n",paciente.id);
	return;
}




