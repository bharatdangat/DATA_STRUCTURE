//CREATE DOUBLY CIRCULAR LINKED LIST AND DISPLAY AN DPRFORM ALL OPERATION.....
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *next,*prev;
}NODE;
#define NODEALLOC (NODE*)malloc(sizeof(NODE))
//1}-
 NODE *create(NODE *list)
 {
  int i,n;
  NODE *newnode,*temp;
  printf("Enter limit-");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   newnode=NODEALLOC;
   printf("Enter value-");
   scanf("%d",&newnode->data);
   if(list==NULL)
   {
    list=temp=newnode;
    temp->next=list;
    list->prev=temp;
   }
   else
   {
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
    temp->next=list;
    list->prev=temp;
   }
  }
  return list;
 }
//2}-
 void display(NODE *list)
 {
  NODE *temp;
  temp=list;
  do
  {
   printf("%d\t",temp->data);
   temp=temp->next;
  }while(temp!=list);
 }
//3}-
  NODE *insertbeg(NODE *list,int num)
  {
    NODE *newnode,*temp;
    newnode=NODEALLOC;
    newnode->data=num;
    for(temp=list;temp->next!=list;temp=temp->next);
    newnode->next=list;
    list->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
    list=newnode;
     return list;
  }
  //ORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
 /*  NODE *insertbeg(NODE *list,int num)
  {
    NODE *newnode,*temp;
    newnode=NODEALLOC;
    newnode->data=num;
  
    newnode->next=list;
    list->prev=newnode;
   for(temp=list;temp->next!=list;temp=temp->next);
    temp->next=newnode;
    newnode->prev=temp;
    list=newnode;
     return list;
  }
*/
  
  //4}-
 NODE *insertend(NODE *list,int num)
 {
  NODE *temp,*newnode;
  newnode=NODEALLOC;
  newnode->data=num;
  for(temp=list;temp->next!=list;temp=temp->next);
  temp->next=newnode;
  newnode->prev=temp;
  newnode->next=list;
  list->prev=newnode;
  return list;
 }
 
 //5}-
  NODE *insertmid(NODE *list,int num,int pos)
  {
   int i;
   NODE *newnode,*temp;
   newnode=NODEALLOC;
   newnode->data=num;
   for(i=1,temp=list;i<pos-1&&temp->next!=list;i++,temp=temp->next);
   newnode->next=temp->next;
   temp->next->prev=newnode;
   temp->next=newnode;
   newnode->prev=temp;
   return list;
  }
  
 //6}_
 NODE *insert(NODE *list,int num,int pos)
 {
  int i;
  NODE *newnode,*temp;
  newnode=NODEALLOC;
  newnode->data=num;
  if(pos==1)
  {
   for(temp=list;temp->next!=list;temp=temp->next);
    newnode->next=list;
    list->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
    list=newnode;
  }
  else
  {
   NODE *newnode,*temp;
   newnode=NODEALLOC;
   newnode->data=num;
   for(i=1,temp=list;i<pos-1&&temp->next!=list;i++,temp=temp->next);
   newnode->next=temp->next;
   temp->next->prev=newnode;
   temp->next=newnode;
   newnode->prev=temp; 
  }
  return list;
 }
 
  //7}-
  NODE *delbeg(NODE *list)
  {
   NODE *temp,*temp1;
   for(temp=list;temp->next!=list;temp=temp->next);
   temp1=temp->next;
   list=list->next;
   temp->next=list;
   list->prev=temp;
   free(temp1);
   return list;
  }
  
  //8}=
  NODE *delend(NODE *list)
  {
   NODE *temp,*temp1;
   for(temp=list;temp->next->next!=list;temp=temp->next);
   temp1=temp->next;
   temp->next=list;
   list->prev=temp;
   free(temp1);
   return list;
  }
  
  //9}-
  NODE *delmid(NODE *list,int pos)
  {
   int i;
   NODE *temp,*temp1;
   for(i=1,temp=list;i<pos-1&&temp->next!=list;i++,temp=temp->next);
   temp1=temp->next;
   temp->next=temp1->next;
   temp1->next->prev=temp;
   free(temp1);
   return list;
  }
  
  //10}-
   NODE *search(NODE *list,int num)
   {
    NODE *temp,*temp1;
    for(temp=list;temp->next!=list;temp=temp->next)
    {
     if(temp->data==num)
     {
      return temp;
     }
    }
    return NULL;
   }
 int main()
 {
  int i,n,num,ch,pos;
  NODE *list=NULL;
  do
  {
  printf("\n1-:CREATE \n2-:DISPLAY \n3-:INSERT BEG \n4-:INSERT END  \n5-:INSERT MIDDLE \n6-:INSERT COMMON\n7-:DELETE BEG \n8-:DELETE END \n9-:DELETE MIDDLE \n10-:SEARCH");
  printf("Enter Choice-");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
         list=create(list);
         break;
   case 2:       
         display(list);
         break;
   case 3:
        printf("Enter Number to insert beg-");
        scanf("%d",&num);
        list=insertbeg(list,num);
        break;
   case 4:
        printf("Enter Number to insert end");
        scanf("%d",&num);
        list=insertend(list,num);
        break;
  case 5:
       printf("Enter number to insert mid");
       scanf("%d",&num);
       printf("Enter Position-");
       scanf("%d",&pos);
       list=insertmid(list,num,pos);
       break;
  case 6:
      printf("Enter number to insert");
       scanf("%d",&num);
       printf("Enter Position-");
       scanf("%d",&pos);
       list=insert(list,num,pos);
       break;
  case 7:
       list=delbeg(list);
        break;
  case 8:
       list=delend(list);
       break;
  case 9:
       printf("Enter Position to delete-");
       scanf("%d",&pos);
       list=delmid(list,pos);
       break;
  case 10:
       printf("Enter Number to search-");
       scanf("%d",&num);
       list=search(list,num);
       if(list==NULL)
       printf("Number is not found");
       else
       printf("Number is found");
        break;
  }
   }while(ch<11);
 }
