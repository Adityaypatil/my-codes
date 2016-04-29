#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct tree
{
char data[10];
struct tree *left,*right;
};

void creat(struct tree **root,char val[10])
{
struct tree *newnode,*temp;

if(*root==NULL)
    {
    temp =(struct tree *)malloc(sizeof(struct tree));
    temp->left = temp->right = NULL;
    strcpy(temp->data,val);
    *root=temp;    
    }
if(strcmp(temp->data,val)<0)
    {
    creat(&(*root)->left,val);
    }
    else
    {
    creat(&(*root)->right,val);
    }

}

void preorder(struct tree *tree) 
{
if(tree!=NULL)
    {
    printf("%s-->",tree->data);
    preorder(tree->left);
    preorder(tree->right);
    }

}



void main()
{
struct tree *root=NULL;
creat(&root,"mov");
creat(&root,"add");
preorder(root);
}

