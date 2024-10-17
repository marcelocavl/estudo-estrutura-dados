#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "paciente.h"

typedef struct filaMedica{
	t_Pilha *filaMedica;
}t_FilaMedica;

void filaMedica_create(t_FilaMedica *filaMedica);
void filaMedica_Alocate_Paciente(t_FilaMedica filaMedica,int id);
void filaMedica_Dump(t_FilaMedica filaMedica);
void filaMedica_Print(t_FilaMedica filaMedica);
void filaMedica_Remove_Paciente(t_FilaMedica filaMedica);
/////////////////////////////////////////////////////////////
void filaMedica_create(t_FilaMedica *filaMedica){
	filaMedica->filaMedica=pilha_create();
	return;
}
/////////////////////////////////////////////////////////////
void filaMedica_Alocate_Paciente(t_FilaMedica filaMedica,int id){
	t_Paciente *paciente=paciente_Create(id);
	pilha_Alocate_Element(filaMedica.filaMedica,paciente,sizeof(t_Paciente));
	return;
}
/////////////////////////////////////////////////////////////
void filaMedica_Dump(t_FilaMedica filaMedica){
	pilha_Dump(filaMedica.filaMedica);
	return;
}
/////////////////////////////////////////////////////////////
void filaMedica_Print(t_FilaMedica filaMedica){
	int i;
	pilha_Go_To_Root_Element(filaMedica.filaMedica);
	for(i=0;i<pilha_Get_Num_Element(filaMedica.filaMedica);i++){
		t_Paciente *newPaciente=get_Data_Element(pilha_Get_Current_Element(filaMedica.filaMedica));
		paciente_Dump(*newPaciente); 
		pilha_Go_Prox_Element(filaMedica.filaMedica);
	}
	return;
}

void filaMedica_Remove_Paciente(t_FilaMedica filaMedica){
	pilha_Desalocate_Element(filaMedica.filaMedica);
	return;
}
