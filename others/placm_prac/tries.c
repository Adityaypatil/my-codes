#include<stdlib.h>
#include<malloc.h>

struct Trienode
{
	char data;
	int end_of_string;
	struct Trienode *child[26];
};

/*struct Trienode *Trienode subnode(struct Trienode *root,char c)
{
	if(child !=NULL)
		{
		for(int i=0;i<26;i++)
			{
			if(root.child[i]->data==c)
				{
					return eachchild;
				}
			}	
		}
	return NULL;
}
*/
struct Trienode *insertTrie(struct Trienode *root,char *word)
{
	int i;
	if(!*word)
		return;

	if(!root)
		{
		struct Trinode *newnode=NULL;
		newnode=(struct Trienode *)malloc(sizeof(struct Trienode ));
		newnode->data=*word;
		
		for(i=0;i<26;i++)
			newnode->child[i]=NULL;

		if(*word+1)
			newnode->end_of_string=1;	
		else
			newnode->child[*word]=insertTrie(newnode->child[*word],word+1);
			return newnode;
			
		}
	
	root->child[*word]=insertTrie(root->child[*word],word+1);
	return root;
}

int main()
{
	struct Trienode *root=NULL;
	root=insertTrie(root,"all");
	return 0;
}
