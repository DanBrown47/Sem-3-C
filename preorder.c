#include<stdio.h>
#include <stdlib.h>
typedef struct tnode
{
    int data;
    struct tnode *right,*left;
}TNODE;
 
TNODE *CreateBST(TNODE *, int);

void Preorder(TNODE *);

void main()
{
    TNODE *root=NULL;		 
    int opn,elem,n,i;
    do
    {
        
        
        printf("\n Press 1-Creation of BST");
       
        printf("\n       2-Traverse in Preorder");
     
        printf("\n       3-Exit\n");
        printf("\n       Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1: root=NULL;
            printf("\n\nBST for How Many Nodes ?");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\nRead the Data for Node %d ?",i);
                scanf("%d",&elem);
                root=CreateBST(root,elem);
            }
            printf("\nBST with %d nodes is ready to Use!!\n",n);
            break;
       
        case 2:
	if(root==NULL)
	printf("Empty tree\n");
	else
	{
 	printf("\n BST Traversal in PREORDER \n");
            Preorder(root);
	}
 	break;
        
        case 3: printf("\n\n Terminating \n\n"); break;
        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
        
    }while(opn != 3);
}
TNODE *CreateBST(TNODE *root, int elem)
{
    if(root == NULL)
    {
        root=(TNODE *)malloc(sizeof(TNODE));
        root->left= root->right = NULL;
        root->data=elem;
        return root;
    }
    else
    {
        if( elem < root->data )
            root->left=CreateBST(root->left,elem);
        else
            if( elem >=root->data )
                root->right=CreateBST(root->right,elem);
            
 
        return(root);
    }
}

 
void Preorder(TNODE *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
 

