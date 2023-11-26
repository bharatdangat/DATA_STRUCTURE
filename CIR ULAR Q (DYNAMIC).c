//CIRCULAR QUEUE(DYNAMIC)

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
  if(rear==NULL)
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
   if(rear==NULL)
   { 
    front=rear=newnode;
    rear->next=front;
   }
   else
   {
    newnode->next=front;
    rear->next=newnode;
    rear=newnode;
   }
   printf("INSERT SUCESSFULLY..............................");
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
    if(front->next==front)
    {
     free(front);
    }
    else
    {
     front=front->next;
     rear->next=front;
     free(temp);
    }
  }
   printf("DELETED VALUE=%d",val);
 }
 
 
 void display()
 {
  temp=front;
  do
  {
   printf("%d\t",temp->data);
   temp=temp->next;
  }while(temp!=front);
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


 
