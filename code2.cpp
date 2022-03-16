#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left,*right;
};
struct node* Newnode(int item)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key =item;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(struct node* root)
{  printf("Inorder:");
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
    printf("\n");
}
void preorder(struct node* root)
{  printf("Preorder:");
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
    printf("\n");
}
void postorder(struct node* root)
{  printf("Postorder:");
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
    printf("\n");
}
struct node* insert(struct node* node,int key)
{
    if(node==NULL)
    return Newnode(key);
    if(key<node->key) node->left=insert(node->left,key);
    else if (key>node->key)node->left=insert(node->left,key);
    return node;
}
int main()
{
    int n;
    struct node* root=NULL;
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&n);
        if(n==1)
        {
            int c;
            printf("Enter Data to Insert");
            scanf("%d",&c);
            insert(root,c);
            
        }
         else if(n==2){
             if(root==NULL) printf("Tree is Empty");
             else
             inorder(root);
            
        }
         else if(n==3){
            if(root==NULL) printf("Tree is Empty");
            else
             preorder(root);
            
        } else if(n==4){
           if(root==NULL) printf("Tree is Empty");
           else
             postorder(root);
        } else if(n==5){
            break;
           
        }
    }
}
