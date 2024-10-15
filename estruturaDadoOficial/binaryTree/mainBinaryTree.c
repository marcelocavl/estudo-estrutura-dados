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
	element2=elementTree_create(&y,4);
	element3=elementTree_create(&z,4);
	//dataDump(element2->adressData,sizeof(element2->sizeofData));
	//dataDump(element3->adressData,sizeof(element3->sizeofData));
	
	elementTree_Add_RightElement(element,element2);
	elementTree_Add_LeftElementTree(element,element3);
	dataDump(elementTree_Get_Data(element->rightElementTree),sizeof(element3->sizeofData));
	dataDump(elementTree_Get_Data(element->leftElementTree),sizeof(element3->sizeofData));
	
	
}

