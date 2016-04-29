#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree	
{	
	struct tree *left;
	char data[10];
	int opcode;
	struct tree *right;	
};
void create(struct tree **root,char val[10],int opcode)
{
	struct tree *newnode;
	if(*root==NULL)
	{	
		newnode=(struct tree*)malloc(sizeof(struct tree));
		newnode->right=NULL;
		newnode->left=NULL;
		strcpy(newnode->data,val);
		newnode->opcode=opcode;
		*root=newnode;
	}
	else
	{
		if(strcmp((*root)->data,val)>0)
		{
			create(&(*root)->left,val,opcode);
			
		}
		if(strcmp((*root)->data,val)<0)
		
		{
			create(&(*root)->right,val,opcode);	
			
		}	
	}
}
void preorder(struct tree *root)
{
	if(root!=NULL)
	{	
		printf("%s\t\t%d\n",root->data,root->opcode);
		preorder(root->left);
		preorder(root->right);
	}
}

main()
{
	struct tree *root=NULL;
	create(&root,"mov",1);	
	create(&root,"add",2);
	create(&root,"sub",3);
	create(&root,"cmp",4);
	create(&root,"bcc",5);
	create(&root,"dpp",6);
	create(&root,"pune",7);
	printf("Mnemonic\tOpcode\n");
	printf("=======================\n");
	preorder(root);
	printf("\n");
	
}











