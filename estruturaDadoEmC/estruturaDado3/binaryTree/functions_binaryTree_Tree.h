#include<stdio.h>
#include<string.h>
#include "functions_binaryTree_Node.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;




//funcoes NODES
void  	   *create_Node(void *data,int size);
void 	             delete_Node(void *data);
//funcoes alocar left right
void allocate_Right(void *node,void *dadNode);
void allocate_left(void *node,void *dadNode);

//funcoes TREE
void       *create_Tree(void *data,int size);
void 	     	     delete_Tree(void *tree);

void    add_Node_Tree(void *tree,void *dado);
void delete_Node_Tree(void *rootNode);
void  		       dump_Tree(void *tree);
void  		dump_Total_Tree(void *child);

void  *find_Node_Tree(void *tree,void *data);
BOOL 	    find_Node(void *node,void *data);
void *find_Next_Node(void *data, void *rootNode);

//funcoes NODES
void  	   *create_Tree(void *data,int size){
	typedef struct tree{
		void  *rootNode;
		int  	  floor;
		int sizeElement;
	}t_Tree;

	t_Tree *newTree;

	if((newTree=malloc(sizeof(t_Tree)))==NULL){
	printf("erro ao alocar arvoré");
	}else{
		void *rootNode=create_Node(data,size);
		newTree->rootNode=rootNode;
		newTree->floor=0;
		newTree->sizeElement=size;
 		printf("arvore alocada com sucesso!\n");
		return newTree;

}


}

void 	     	     delete_Tree(void *tree);

void    add_Node_Tree(void *root_Node,void *dado){
	void  *root_Node_Left;
	void *root_Node_Right;
	void *value_Root_Node;
	*(long int *)(&root_Node_Left)=*(long int *)(root_Node+16);
	*(long int *)(&root_Node_Right)=*(long int *)(root_Node+24);
	*(long int *)(&value_Root_Node)=*(long int *)(root_Node);

	if(memcmp(value_Root_Node,dado,4)>0){
		if(root_Node_Left!=NULL){
			add_Node_Tree(root_Node_Left,dado);
		}else{
			void *leftNode=create_Node(dado,4);
			*(long int *)(root_Node+16)=*(long int *)(&leftNode);
		}
	


	}else{
		if(root_Node_Right!=NULL){
			add_Node_Tree(root_Node_Right,dado);
		}else{

			void *rightNode=create_Node(dado,4);
			*(long int *)(root_Node+24)=*(long int *)(&rightNode);
		}
	



	}







	return;

	}


void  		       dump_Tree(void *tree);


void  		 dump_Total_Tree(void *child){
	void *child_left;
	void *child_right;
	*(long int *)(&child_right)=*(long int*)(child+24);
	*(long int *)(&child_left)=*(long int*)(child+16);
	if(child!=NULL){
		dumpNode(child);
	if(child_left!=NULL || child_right!=NULL){	
		
		if(child_left!=NULL){
			dump_Total_Tree(child_left);
		}
		if(child_right!=NULL){
			dump_Total_Tree(child_right);
		}
		
		return;


	}
 }



}



void  *find_Node_Tree(void  *node,void *data){

	void *nodeLeft;
	void *nodeRight;
	void *dataNode;
	*(long int *)(&nodeLeft)=*(long int *)(node+16);
	*(long int *)(&nodeRight)=*(long int *)(node+24);
	*(long int *)(&dataNode)=*(long int *)(node);

	if(find_Node(node,data)){
		printf("encontrei!!\n"); 
		dumpNode(node);
		return node;
	}else{
		if(nodeLeft!=NULL && (memcmp(dataNode,data,4)>0)){
			printf("indo para a esquerda!\n");
			find_Node_Tree(nodeLeft,data);
		}

		if(nodeRight!=NULL && (memcmp(dataNode,data,4)<0)){
			printf("indo para a direita\n");
			find_Node_Tree(nodeRight,data);
		}

	}
}
void delete_Node_Tree(void *rootNode){

printf("dump dentro da funcao!\n");
	dumpNode(rootNode);
	void *LeftNodeToDelete;
	void *RightNodeToDelete;

	*(long int* )(&LeftNodeToDelete)=*(long int *)(rootNode+16);
	*(long int* )(&RightNodeToDelete)=*(long int *)(rootNode+24);


	if(LeftNodeToDelete==NULL && RightNodeToDelete==NULL){
		delete_Node(rootNode);
		return;
	}else{
		if(LeftNodeToDelete!=NULL){
printf("passei!\n");
			delete_Node_Tree(LeftNodeToDelete);
		}
		if(RightNodeToDelete!=NULL){
printf("entrei na direita\n");
			delete_Node_Tree(RightNodeToDelete);
		}
	}
	void *n=NULL;
	printf("cheguei ate aq\n");
	*(long int * )(rootNode+24)=*(long int *)(&n);
	*(long int * )(rootNode+16)=*(long int *)(&n);

}







/*

void *find_Next_Node(void *data, void *rootNode){
		void *LeftNodeToDelete;
		void *RightNodeToDelete;
		void *dataLeft;
		void *dataRight;
		

	*(long int* )(&LeftNodeToDelete)=*(long int *)(rootNode+16);
printf("printando aqui denovoqweqweq\n");
	*(long int* )(&RightNodeToDelete)=*(long int *)(rootNode+24);
printf("printando aqui denovoqweqweq\n");
if(*(long int *)(LeftNodeToDelete)!=NULL){
	
}
	*(long int *)(&dataLeft)=*(long int*)(LeftNodeToDelete);
printf("printando aqui denovoqweqweq\n");
	*(long int *)(&dataRight)=*(long int*)(RightNodeToDelete);
printf("printando aqui denovoqweqweq\n");
	if(!(memcmp(dataLeft,data,4)==0)){
		delete_Node_Tree(LeftNodeToDelete);
		void *n=NULL;
		printf("cheguei ate aq\n");
		*(long int * )(rootNode+16)=*(long int *)(&n);
		return LeftNodeToDelete;
	}

	if(!(memcmp(dataRight,data,4))){
		delete_Node_Tree(RightNodeToDelete);
		void *n=NULL;
		*(long int * )(rootNode+24)=*(long int *)(&n);
		return RightNodeToDelete;
	}

	if((memcmp(dataLeft,data,4))>0){
		find_Next_Node(data,LeftNodeToDelete);
	}
	if((memcmp(dataRight,data,4))<0){
printf("entrei aqui\n");
		find_Next_Node(data,RightNodeToDelete);
	}



}
*/

void *find_Next_Node(void *data, void *rootNode){

	void *leftNode;
	void *rightNode;
	void *dataLeft;
	void *dataRight;

	*(long int* )(&leftNode)=*(long int *)(rootNode+16);
	*(long int* )(&rightNode)=*(long int *)(rootNode+24);



	if(((long int *)(*(long int *)(rootNode+16)))==NULL){
		leftNode=NULL;
	}else{
		*(long int* )(&leftNode)=*(long int *)(rootNode+16);
		*(long int *)(&dataLeft)=*(long int *)(leftNode);
	}


	if(((long int *)(*(long int *)(rootNode+24)))==NULL){
		rightNode=NULL;
	}else{
		*(long int* )(&rightNode)=*(long int *)(rootNode+24);
		*(long int *)(&dataRight)=*(long int *)(rightNode);
	}
///////////////////////////////////////////////////////////////////

	if(leftNode!=NULL && (!memcmp(dataLeft,data,4))){
		delete_Node_Tree(leftNode);
		void *n=NULL;
		*(long int * )(rootNode+16)=*(long int *)(&n);
		return leftNode;
	}
	
	if(rightNode!=NULL && (!memcmp(dataRight,data,4))){
		delete_Node_Tree(rightNode);
		void *n=NULL;
		*(long int * )(rootNode+24)=*(long int *)(&n);
		return rightNode;
	}


	if(leftNode!=NULL && ((memcmp(dataLeft,data,4))>0)){
		find_Next_Node(data,leftNode);
	}

	if(rightNode!=NULL && ((memcmp(dataRight,data,4))<0)){
		find_Next_Node(data,rightNode);
	}







}












