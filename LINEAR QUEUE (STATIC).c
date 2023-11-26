//LINEAR QUEUE(STATIC)
#include<stdio.h>
#include<malloc.h>
#define 
struct Queue
{
 int data[MAX];
 int front,rear;
}*q;

void initq()
{
 q->front=-1;
 q->rear=-1;
}

int isempty()
{
 if(q->front==-1||q->front>q->rear)
 return 1;
 else
 return 0;
 }
 
 int isfull()
 {                //DOUBLE EQUAL TO ----IMP....................
  if(q->rear==MAX-1)
  return 1;
  else
  return 0;
 }
 
 void insertq(int num)
 {
  if(isfull())
  {
   printf("Queue is full don't insert...");
  }
  else
  {
    if(q->front==-1)      //VVVVVVVVVVVVVVVVVVVVVIMP
    {
     q->front=0;
    }
   q->rear++;
   q->data[q->rear]=num;
   printf("Insert sucessfully.............");
  }
 }

 void deleteq()
 {
  int val;
  if(isempty())
  {
   printf("Queue is underflow............. ");
  }
  else
  {
   val=q->data[q->front];
   q->front++;
   printf("Deleted value=%d",val);
  }
 }
 
 void display()
 {
  for(i=q->front;i<=q->rear;i++)
  {
   printf("%d\t",q->data[i]);
  }
 }
 int main()
 {
  init();               //vimppppppppppppppppppppppppppppp
  int i,n,ch,num;
  do
  {
   printf(("1-INSERT 2-DELETE 3-DISPLAY");
   printf("ENTER CHOICE-");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: printf("Enter number-");
          scanf("%d",&num);
          insertq(num);
          break;
    case 2: deleteq();
         break;
    case 3:display();
         break;
   }
  }while(ch<4);
 }
