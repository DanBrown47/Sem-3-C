#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
int data;
struct tnode *right,*left;
}
TNODE;
TNODE *createBST(TNODE *,int);
void preorder(TNODE *);
void main()
{
TNODE *root=NULL;
int opn,elem,n,i;
do
{
printf("\n press 1-creation of BST");
printf("\n       2-traverse in preorder");
printf("\n       3-exit");
printf("\n       your option ?");
scanf("%d",&opn);
switch(opn)
{
case 1:
root=NULL;
printf("\n\nBST for how many nodes?");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n read the data for node %d ?",i);
scanf("%d",&elem);
root=createBST(root,elem);
}
printf("\n BST with %d nodes is ready to use!!\n",n);
break;
case2:
if (root==NULL)
printf("empty tree\n");
else
{
printf("\n BST traversal in preorder\n ");
preorder(root);
}
break;
case3:
printf("\n\n terminating\n\n");
break;
defult:
printf("\n\n invalid option !!! try again!!\n\n");
break;
}
}
while(opn !=3);
}
TNODE *createBST(TNODE *root,int elem)
{
if(root==NULL)
{
root=(TNODE *)malloc(sizeof(TNODE));
root->left=root->right=NULL;
root->data=elem;
return root;
}
else
{
if(elem<root->data)
root->left=createBST(root->left,elem);
else
if(elem>=root->data)
root->right=createBST(root->right,elem);
return(root);
}
}
void preorder(TNODE *root)
{
if(root!=NULL)
{
printf("%d",root->data);
printf("oi");
preorder(root->left);
preorder(root->right);
}
}

