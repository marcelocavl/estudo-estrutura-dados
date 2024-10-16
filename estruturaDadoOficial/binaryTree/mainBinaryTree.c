#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "binaryTree.h"


int main()
{
/*
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
	//dataDump(elementTree_Get_Data(element->rightElementTree),sizeof(element3->sizeofData));
	//dataDump(elementTree_Get_Data(element->leftElementTree),sizeof(element3->sizeofData));
	elementTree_Dump(element);
	
*/	
	int x=12;
	t_BinaryTree *binaryTree=binaryTree_Create(&x,sizeof(int));
	int y=13;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&y,sizeof(int));
	int z=10;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&z,sizeof(int));
	int j=11;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=1;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
	j=15;
	binaryTree_Add(binaryTree,(binaryTree->rootElement),&j,sizeof(int));
/*
	t_ElementTree *test=elementTree_Get_RightElement(binaryTree->rootElement);
	t_ElementTree *test2=elementTree_Get_LeftElement(binaryTree->rootElement);
	elementTree_Dump(binaryTree->rootElement);
	elementTree_Dump(test);
	elementTree_Dump(test2);
*/
	j=10;
	printf("%d\n",binaryTree->numElements);	
	t_ElementTree *test=binaryTree_Search_penultimate(binaryTree,binaryTree->rootElement,&j);
	elementTree_Dump(test);
		

}

