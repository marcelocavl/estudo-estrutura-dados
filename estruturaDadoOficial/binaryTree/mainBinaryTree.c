#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "elementTree.h"
#include "functions_Show.h"


int main()
{
	t_ElementTree *element;    
	t_ElementTree *element2;    
	t_ElementTree *element3;    
	int x=12;
	int y=8;
	int z=7;
	element=elementTree_create(&x,sizeof(x));
	dataDump(element->adressData,sizeof(element->sizeofData));
	t_ElementTree *element2;    
}

