//LINEAR QUEUE(DYNAMIC)
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define NODEALLOC (struct node*)malloc(sizeof(struct node));
struct node
{
 int data;
 struct node *next;
}*newnode,*temp,*front,*rear;

void init()
{
 front=rear=NULL;
}

 int isempty()
 {
  if(front==NULL)
  {
   return 1;
  }
  else
  return 0;
 }
 
//DYNAMIC SATI ISFULL() YET NAHI.........................

 void insert(int num)
 {
  newnode=NODEALLOC;
  newnode->data=num;
  newnode->next=NULL;
  if(front==NULL)
  {
   front=rear=newnode;
  }
  else
  {
   rear->next=newnode;
   rear=newnode;
  }
  printf("Insert Sucessfully...............");
 }
 
 void delete()
 {
  int val;
  if(isempty())
  {
   printf("Queue is empty don't delete.");
  }
  else
  {
   val=front->data;
   temp=front;
   front=front->next;
   free(temp);
   printf("Deleted value=%d",val);
  }
 }
 
 void display()
 {
  for(temp=front;temp!=NULL;temp=temp->next)
  {
   printf("%d\t",temp->data);
  }
 }
 
 int main()
 {
  init();
  int i,n,ch,num;
  do
 {
  printf("\n1-INSERT \n2-DELETE \n3-DISPLAY");
  printf("\nEnter Choice-");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
        printf("Enter Number-");
        scanf("%d",&num);
        insert(num);
break;
  case 2:
        delete();
        break;
        //...............................OR....................................................................................>
      
  
  case 3:
       display();
       break;
  }
 }while(ch<4);
}


 
