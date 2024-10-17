#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "filaEncadeada.h"

int main() {
	int x=12;
	int y=3;
	int g=2;

	void *element=element_Create(&x,4);
	delete_Element(element);
	void *list=list_Create();
	list_Alocate_Element(list,&x,sizeof(int));
	list_Alocate_Element(list,&y,sizeof(int));
	list_Alocate_Element(list,&g,sizeof(int));

	list_Desalocate_Element(list,&y);	
	list_Dump_List(list);


	return 0;
}

