#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"


int main() {
	int x=12;	
	int x2=2;	
	int x3=6;	
	int x4=15;	
	int x5=7;	
	void *fila=fila_create();
	fila_Alocate_Element(fila,&x,sizeof(int));
	fila_Alocate_Element(fila,&x2,sizeof(int));
	fila_Alocate_Element(fila,&x3,sizeof(int));
	fila_Alocate_Element(fila,&x4,sizeof(int));
	fila_Alocate_Element(fila,&x5,sizeof(int));

	fila_Desalocate_Element(fila);
	fila_Desalocate_Element(fila);
	fila_Desalocate_Element(fila);


	fila_Dump(fila);
	return 0;
}

