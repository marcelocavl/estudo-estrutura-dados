#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions_binaryTree_Tree.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;





///////////////////////////////////////////////////
//void addressDump(void *address);
//void dataDump(void *address,int size);
///////////////////////////////////////////////////

//funcoes NODES
void  	   *create_Node(void *data,int size);
void 	             delete_Node(void *data);
//funcoes alocar left right
void allocate_Right(void *node,void *dadNode);
void allocate_left(void *node,void *dadNode);

//funcoes TREE
void       *create_Tree(void *data,int size);
void 	     	     delete_Tree(void *tree);

void    add_Node_Tree(void *root_Node,void *dado);
void delete_Node_Tree(void *rootNode);
void  		       dump_Tree(void *tree);
void  		dump_Total_Tree(void *child);

void  *find_Node_Tree(void *tree,void *data);
BOOL 	    find_Node(void *node,void *data);
void *find_Next_Node(void *data, void *rootNode);

int main() {
// criando árvore
	int x=12;
	void *tree=create_Tree(&x,4);
//adicionando novos elementos a tree
	 x=8;
	add_Node_Tree((long int *)(*(long int *)(tree)),&x);
	 x=4;
	add_Node_Tree((long int *)(*(long int *)(tree)),&x);
	 x=2;
	add_Node_Tree((long int *)(*(long int *)(tree)),&x);

	 x=5;
	add_Node_Tree((long int *)(*(long int *)(tree)),&x);

	x=4;

	find_Next_Node(&x,(long int *)(*(long int *)(tree)));


	dump_Total_Tree((long int *)(*(long int *)(tree)));
	/*
	int x=5;
	
	void *tree=create_Tree(&x,4);

	x=10;
add_Node_Tree((long int *)(*(long int *)(tree)),&x);
	x=3;
add_Node_Tree((long int *)(*(long int *)(tree)),&x);

	x=12;
add_Node_Tree((long int *)(*(long int *)(tree)),&x);

	x=8;
add_Node_Tree((long int *)(*(long int *)(tree)),&x);

	x=4;
add_Node_Tree((long int *)(*(long int *)(tree)),&x);




	x=3;

find_Next_Node(&x,(long int *)(*(long int *)(tree)));


dump_Total_Tree((long int *)(*(long int *)(tree)));
*/
	/*
	void *data=malloc(sizeof(int));
	memset(data,0,4);
	*(int *)data=4;

	void *tree=create_Tree(data,4);
	void *data2=malloc(sizeof(int));
	memset(data2,0,4);
	*(int *)data2=7;



	add_Node_Tree((long int*)(*(long int*)tree),data2);



	void *data3=malloc(sizeof(int));
	memset(data3,0,4);
	*(int *)data3=12;



	void *data4=malloc(sizeof(int));
	memset(data4,0,4);
	*(int *)data4=1;




	void *data5=malloc(sizeof(int));
	memset(data5,0,4);
	*(int *)data5=5;

	void *data6=malloc(sizeof(int));
	memset(data6,0,4);
	*(int *)data6=15;


	add_Node_Tree((long int*)(*(long int*)tree),data3);
	add_Node_Tree((long int*)(*(long int*)tree),data4);
	add_Node_Tree((long int*)(*(long int*)tree),data5);
	add_Node_Tree((long int*)(*(long int*)tree),data6);
	void *deleteNode=find_Node_Tree((long int *)(*(long int *)tree),data3);
	dump_Total_Tree((long int *)(*(long int *)(tree)));

	void *rootTree;
	*(long int *)(&rootTree)=*(long int *)(tree);

	void *node=find_Next_Node(data3,rootTree);
printf("printando depois de tudo isso!\n");
	dump_Total_Tree((long int *)(*(long int *)(tree)));
*/
	return 0;
}
