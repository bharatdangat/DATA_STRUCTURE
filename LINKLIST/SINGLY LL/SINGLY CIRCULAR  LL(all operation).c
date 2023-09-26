//CREATE SINGLY CIRCULAR LINKED LIST AND DISPALAY AND PERFORM ALL OPERATION............
#include<stdio.h>
#include<stdlib.h>

typedef struct node
 {
  int data;
  struct node *next;
 }NODE;
 #define NODEALLOC (NODE *)malloc(sizeof(NODE))
//1]-
 NODE *create(NODE *list)
 { 
  NODE *newnode,*temp;
  int i,n;
  printf("Enter Limt");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   newnode=NODEALLOC;
   printf("Enter value:");
   scanf("%d",&newnode->data);
   if(list==NULL)
   {
    list=temp=newnode;
    newnode->next=list;
   }
   else
   {
     temp->next=newnode;
     temp=newnode;
     newnode->next=list;
   }
  }
  return  list;
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
   NODE *temp,*newnode;
   newnode=NODEALLOC;
   newnode->data=num;
   
   newnode->next=list;
   for(temp=list;temp->next!=list;temp=temp->next);
   temp->next=newnode;
   list=newnode;
   return list;
  }
  //4}-
  NODE *insertend(NODE *list,int num)
  {
   NODE *temp,*newnode;
   newnode=NODEALLOC;
   newnode->data=num;
   for(temp=list;temp->next!=list;temp=temp->next);
   newnode->next=list;
   temp->next=newnode;
   return list;
  }
  //5}-
  NODE *insertmid(NODE *list,int num,int pos)
  {
   int i;
   NODE *temp,*newnode;
   newnode=NODEALLOC;
   newnode->data=num;
   for(i=1,temp=list;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
   newnode->next=temp->next;  //(adhi pudhch jodaych.....)
   temp->next=newnode;
   return list;
  }
//6}-
 NODE *delbeg(NODE *list)
 {
  NODE *temp,*temp1;
  for(temp=list;temp->next!=list;temp=temp->next);
  temp1=temp->next;
  list=list->next;
  temp->next=list;
  free(temp1);
  return list;
 }
 
 //7}-
  NODE *delend(NODE *list)
  {
   NODE *temp,*temp1;
   for(temp=list;temp->next->next!=list;temp=temp->next);
   temp1=temp->next;
   temp->next=list;
   free(temp1);
   return list;
  }
  
  //8}-
   NODE *delmid(NODE *list,int pos)
   {
    int i;
    NODE *temp,*temp1;
    for(i=1,temp=list;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return list;
   }
   //9}-
   NODE *search(NODE *list,int num)
   {
    NODE *temp;
     temp=list;
     do
     {
       if(temp->data=num)
       {
        return temp;
       }
     }while(temp!=list);
     return NULL;
   }
int main()
 {
 int i,n,ch,pos,num;
 NODE *list=NULL;
 do
 {
 printf("\n1-:CREATE \n2-:DISPLAY \n3-:INSERT BEG \n4-:INSERT END \n5-:INSERT     MIDDLE \n6-:DELETE BEG \n7-:DELETE END \n8-:DELETE MIDDLE \n9-:SEARCH");
   
 printf("Enter choice-");
 scanf("%d",&ch);
 switch(ch)
  {
  case 1: list=create(list);
         break;
  case 2: display(list);
         break;
  case 3:
          printf("Enter Number to insert beg=");
          scanf("%d",&num);
          list=insertbeg(list,num);
          break;
    case 4:
          printf("Enter No to insert end=");
          scanf("%d",&num);
          list=insertend(list,num);
          break;
    case 5:
          printf("Enter No to insert middle=");
          scanf("%d",&num);
          printf("Enter Position=");
          scanf("%d",&pos);
          list=insertmid(list,num,pos);
          break;
   case 6:
        list=delbeg(list);
        break;
  case 7:
       list=delend(list);
       break;
  case 8:
       printf("Enter middle Position to delete-");
       scanf("%d",&pos);
       list=delmid(list,pos);
       break;
 case 9:
     printf("Enter number to search-");
     scanf("%d",&num);
     list=search(list,num);
     if(list==NULL)
     {
      printf("Number is not found");
     }
     else
     {
      printf("Number is found");
     }
     break;
  }
 }while(ch<10); 
}
