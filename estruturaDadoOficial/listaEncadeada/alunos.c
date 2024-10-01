#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "filaEncadeada.h"

typedef struct aluno{
	int idade;
	int matricula;
}t_Aluno;

void dump_Aluno(t_Aluno *aluno){
	printf("IDADE ALUNO : %i\n",aluno->idade);	
	printf("MATRICULA ALUNO : %i\n",aluno->matricula);
	return;

}

int main() {

 t_Aluno bruno = {12, 123};
    t_Aluno carlos = {1, 124};
    t_Aluno maria = {10, 125};
    t_Aluno torres = {178, 126};	
    /*
	    t_Aluno bruno;
	    bruno.idade=12;
	    bruno.matricula=123;

	    t_Aluno carlos;
	    bruno.idade=1;
	    bruno.matricula=123;

	    t_Aluno maria;
	    bruno.idade=10;
	    bruno.matricula=123;


	    t_Aluno torres;
	    bruno.idade=178;
	    bruno.matricula=123;
*/
	    void *list=list_Create();
	    list_Alocate_Element(list,&bruno,sizeof(t_Aluno));
	    list_Alocate_Element(list,&carlos,sizeof(t_Aluno));
	    list_Alocate_Element(list,&maria,sizeof(t_Aluno));
	    list_Alocate_Element(list,&torres,sizeof(t_Aluno));
	dump_Aluno(&maria);

	dump_Aluno( (t_Aluno *)get_Data_Element(list_get_This_Element(list,&maria)));
		

	    return 0;
}

