#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
char data[10];
struct tree *left,*right;
};

void creat(struct tree **root,char val[10])
{
	struct tree *newnode,*temp;
	temp=*root;
	if(*root==NULL)
	{
		temp =(struct tree *)malloc(sizeof(struct tree));
		temp->left = temp->right = NULL;
		strcpy(temp->data,val);
		*root=temp;    
	}
	else if(strcmp(temp->data,val)>0)
	{
		creat(&((*root)->left),val);
	}
	else
	{
		creat(&((*root)->right),val);
	}

}

void inorder(struct tree *tree) 
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%s-->",tree->data);
		inorder(tree->right);
	}

}



void main()
{
	struct tree *root=NULL;
	creat(&root,"MOV");
	creat(&root,"ADD");
	creat(&root,"ADDI");
	creat(&root,"ADC");
	creat(&root,"SUB");
	creat(&root,"SUBI");
	creat(&root,"INC");
	creat(&root,"DEC");
	creat(&root,"MUL");
	creat(&root,"DIV");
	creat(&root,"CLC");
	creat(&root,"CMP");
	creat(&root,"ROL");
	creat(&root,"SAL");
	creat(&root,"AND");
	creat(&root,"NOP");
	creat(&root,"NOT");
	creat(&root,"OR");
	creat(&root,"XOR");
	creat(&root,"JMP");
	creat(&root,"LOOP");
	creat(&root,"CALL");
	creat(&root,"RET");
	creat(&root,"JCC");
	creat(&root,"PUSH");
	creat(&root,"POP");
	creat(&root,"MOVS");
	creat(&root,"REP");
	inorder(root);
}

