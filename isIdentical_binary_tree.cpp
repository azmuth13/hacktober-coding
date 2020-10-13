#include <stdlib.h>
#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



/*
two binary trees are said to be identical
if left subtree of first tree is exactly 
similar to left subtree of the 2nd tree 
and right subtree of first tree
is exactly similar to right subtree
of 2nd tree for each node of first tree
*/


struct treenode{
	int value;
	struct treenode *left;
	struct treenode *right;
};

// allocates a node
struct treenode *getnode()
{
	struct treenode *temp;
	temp = (struct treenode *)malloc(sizeof(struct treenode));
	temp->left = NULL;
	temp->right=NULL;
	return temp;
}

// This insert is for BST (binary search tree)
struct treenode *insert(struct treenode *root,int x)
{
	struct treenode *p, *q;
	q = getnode();
	q->value = x;
	q->left = NULL;
	q->right = NULL;
	
	if(root == NULL)
	return (q);
	
	p = root;
	
	while(1)
	{
		if(x<p->value)
		{
			if(p->left == NULL)
			break;
			p = p->left;
		}
		else
		{
			if(p->right == NULL)
			break;
			p=p->right;
		}
	}
	
	if(x<p->value)
	p->left = q;
	else
	p->right = q;
	
	return (root);
}

void printInorder(struct treenode *root)
{
	if(root==NULL)
	return;
	
	printInorder(root->left);
	
	printf("%d ", root->value);
	
	printInorder(root->right);
	
}


int isIdentical(struct treenode *t1, struct treenode *t2)
{
	if(t1==NULL && t2 == NULL)
	return (1);
	
	if(t1==NULL) return 0;
	if(t2==NULL) return 0;
	
	if(t1->value == t2->value)
	if(isIdentical(t1->left,t2->left))
	if(isIdentical(t1->right,t2->right))
	return 1;
	
	return 0;
}

int main()
{
	

    struct treenode *root2;
	root2 = getnode();
	root2->value = 2;
	root2->left = getnode();
	root2->left->value = 1;
	root2->right = getnode();
	root2->right->value = 4;
	printInorder(root2);
	printf("\n");
	
	struct treenode *root3;
	root3 = getnode();
	root3->value = 2;
	root3->left = getnode();
	root3->left->value = 1;
	root3->right = getnode();
	root3->right->value = 4;
	printInorder(root3);
	printf("\n");
	
	if(isIdentical(root2,root3))
	printf("Yes equal\n");
	else
	printf("Not equal\n");

return 0;
	
}
