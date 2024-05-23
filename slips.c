//Q.1) Implement a Binary search tree (BST) library (btree.h) with operations – create, insert,search,inorder,preorder,postorder
//Write a menu driven program that performs the above operations.

//Q.2) Write a program which uses binary search tree library and counts the total leaf nodes in the tree.
//int countLeaf(T) – returns the total number of leaf nodes from BST

//Q.3) Write a program which uses binary search tree library and counts the total nodes in the tree.
//int count(T) – returns the total number of nodes from BST

#include<stdio.h>
#include<stdlib.h>
#define MEMORY (struct node*) malloc(sizeof(struct node)) 
typedef struct node
{
 int data;
 struct node *left,*right;
}NODE;
NODE *create(NODE *root)
{
 int i,n;
 NODE *newnode,*temp,*parent;
 printf("Enter Limit");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=MEMORY;
  printf("Enter value");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  
  if(root==NULL)
  {
   root=newnode;
   continue;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<temp->data)
   temp=temp->left;
   else
   temp=temp->right;
  }
  if(newnode->data<parent->data)
  parent->left=newnode;
  else
  parent->right=newnode;
 }
 return root;
}

NODE *insert(NODE *root)
{
 int i,n;
 NODE *newnode,*temp,*parent;
  newnode=MEMORY;
  printf("Enter value to insert-");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  
  if(root==NULL)
  {
   root=newnode;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<temp->data)
   temp=temp->left;
   else
   temp=temp->right;
  }
  if(newnode->data<parent->data)
  parent->left=newnode;
  else
  parent->right=newnode;
 
 return root;
}

void inorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  inorder(temp->left);
  printf("%d\t",temp->data);
  inorder(temp->right);
 }
}

void preorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  printf("%d\t",temp->data);
  preorder(temp->left);
  preorder(temp->right);
 }
}

void postorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  postorder(temp->left);
  postorder(temp->right);
  printf("%d\t",temp->data);
 }
}

int search(NODE *root)
{
 int num;
 NODE *temp=root;
 printf("Enter Value to search-");
 scanf("%d",&num);
 while(temp!=NULL)
 {
 if(num==temp->data)
 return num;
 else if(num<temp->data)
  temp=temp->left;
 else
 temp=temp->right;
 }
 return -1;
}

int totalnode(NODE *root)
{
 NODE *temp=root;
 static int count=0;
 if(temp!=NULL)
 {
  count++;
  totalnode(temp->left);
  totalnode(temp->right);
 }
 return count;
}

int leafnode(NODE *root)
{
 NODE *temp=root;
 static int count=0;
 if(temp!=NULL)
 {
  if(temp->left==NULL&&temp->right==NULL)
  {
  count++;
  }
  leafnode(temp->left);
  leafnode(temp->right);
 }
 return count;
}

int main()
{
 NODE *root=NULL;
 int ch;
 do
 {
 printf("\n 1-CREATE \n2-INSERT \n3-INORDER \n4-PREORDER \n5-POSTORDER \n6-SEARCH \n7-TOTAL NODE       \n8-LEAF NODE");
 printf("\nEnter Your Choice-");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
      root=create(root);
      printf("create succ........");
      break;
 case 2:
      root=insert(root);
      printf("insert succ...........");
      break;
case 3:
     printf("Inorder Dispaly-");
     inorder(root);
     break;
case 4:
     printf("preorder Dispaly-");
     preorder(root);
     break;
case 5:
    printf("postorder Display-");
    postorder(root);
    break;
case 6:
    if(search(root))
    printf("Number is found");
    else
    printf("Number is not found");
   break;
case 7:
     printf("TOTAL NODE=%d",totalnode(root));
     break;
case 8:
    printf("TOTAL LEAF NODE=%d",leafnode(root));
    break;
}
}while(ch<9);
}

Q.2) Write a C program which uses Binary search tree library and implements following function:
int sumeven(T) – returns sum of all even numbers from BST

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *left,*right;
}NODE;

NODE *create(NODE *root)
{
 int i,n,num;
 NODE *temp,*parent,*newnode;
 printf("Enter limit-");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(NODE*)malloc(sizeof(NODE));
  printf("Enter value");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
   root=newnode;
   continue;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<temp->data)
   temp=temp->left;
   else
   temp=temp->right;
 }
  if(newnode->data<parent->data)
  parent->left=newnode;
  else
  parent->right=newnode;
 
 }
 return root;
}

int sumeven(NODE *root)
{
   int sum=0;
 NODE *temp=root;
 if(temp!=NULL)
 {
  if(temp->data %2==0)
  {
   sum=sum+temp->data;
  }
    sum=sum+sumeven(temp->left);
   sum=sum+sumeven(temp->right);
   }
   return sum;
}
int main()
{
 NODE *root=NULL;
 root=create(root);
 if(sumeven(root))
 {
  printf("sum even =%d",sumeven(root));
 }
}

Q.2) Write a C program which uses Binary search tree library and implements following function:
int sumodd(T) – returns sum of all odd numbers from BST

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *left,*right;
}NODE;

NODE *create(NODE *root)
{
 int i,n,num;
 NODE *temp,*parent,*newnode;
 printf("Enter limit-");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(NODE*)malloc(sizeof(NODE));
  printf("Enter value");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
   root=newnode;
   continue;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<temp->data)
   temp=temp->left;
   else
   temp=temp->right;
 }
  if(newnode->data<parent->data)
  parent->left=newnode;
  else
  parent->right=newnode;
 
 }
 return root;
}

int sumodd(NODE *root)
{
   int sum=0;
 NODE *temp=root;
 if(temp!=NULL)
 {
  if(temp->data %2==1)
  {
   sum=sum+temp->data;
  }
    sum=sum+sumodd(temp->left);
   sum=sum+sumodd(temp->right);
   }
   return sum;
}
int main()
{
 NODE *root=NULL;
 root=create(root);
 if(sumodd(root))
 {
  printf("sum odd =%d",sumodd(root));
 }
}

//Q.2) Write a C program which uses Binary search tree library and implements following function:
//mirror(T) – converts given tree into its mirror image. [10]
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *left,*right;printf("\n DISPALY-");
 
}NODE;

NODE *create(NODE *root)
{
 int i,n,num;
 NODE *temp,*parent,*newnode;
 printf("Enter limit-");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  newnode=(NODE*)malloc(sizeof(NODE));
  printf("Enter value");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
   root=newnode;
   continue;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<temp->data)
   temp=temp->left;
   else
   temp=temp->right;
 }
  if(newnode->data<parent->data)
  parent->left=newnode;
  else
  parent->right=newnode;
 
 }
 return root;
}

NODE *mirror(NODE *root)
{
 NODE *temp=root,*temp1;
 if(temp!=NULL)
 {
  if(temp->left!=NULL)
  mirror(temp->left);
  if(temp->right!=NULL)
  mirror(temp->right);
  
  temp1=temp->left;
  temp->left=temp->right;
  temp->right=temp1;
 }
 return root;
}

void inorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  inorder(temp->left);
  printf("%d\t",temp->data);
  inorder(temp->right);
 }
}

int main()
{
 NODE *root=NULL;
 root=create(root);
 printf("\n DISPALY-");
 inorder(root);
 root=mirror(root);
 printf("\n MIRROR DISPALY-");
 inorder(root);
}








Write a C program which uses Binary search tree library and implements following function with
recursion:
T copy(T) – create another BST which is exact copy of BST which is passed as parameter.
