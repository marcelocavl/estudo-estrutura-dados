#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "filaMedica.h"


int main() {
/*
	t_FilaMedica filaMedica;
	filaMedica_create(filaMedica);
	filaMedica_Alocate_Paciente(filaMedica,3);
	filaMedica_Dump(filaMedica);
	return 0;
	*/
	t_FilaMedica filaMedica;
	filaMedica_create(&filaMedica);
	filaMedica_Alocate_Paciente(filaMedica,3);
	 filaMedica_Alocate_Paciente(filaMedica,12);
	 filaMedica_Alocate_Paciente(filaMedica,8);
	 filaMedica_Alocate_Paciente(filaMedica,4);
	 filaMedica_Alocate_Paciente(filaMedica,9);
	 filaMedica_Alocate_Paciente(filaMedica,5);
	 filaMedica_Alocate_Paciente(filaMedica,2);
	//filaMedica_Dump(filaMedica);
	filaMedica_Print(filaMedica);
printf("===================================================\n");
	filaMedica_Remove_Paciente(filaMedica);
	filaMedica_Remove_Paciente(filaMedica);
	filaMedica_Remove_Paciente(filaMedica);
	filaMedica_Remove_Paciente(filaMedica);
	filaMedica_Remove_Paciente(filaMedica);
	filaMedica_Print(filaMedica);

	return 0;
}

