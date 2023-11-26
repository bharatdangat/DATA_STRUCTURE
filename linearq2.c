//LINEAR QUEUE
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct Queue
{
 int a[MAX];
 int front,rear;
}*q;

void initq()
{
 q=(struct Queue*)malloc(sizeof(struct Queue)); 
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
                //vimp......................................
                      //vimp..................................
int isfull()                       //IF CHYA CONDITION MADHE = = TAKNE...
{
 if(q->rear==MAX-1)
  return 1;
 else
 return 0;
}

void Add(int num)
{
int i;
if(isfull()==1)
printf("Queue is Full ");
else
{
for(i=q->rear;i>q->front;i--)
{
if(num<q->[i])
q->[i+1]=q->[i];
else
break;
}
q->[i+1]=num;
q->rear++;
}
}
int Delete()
{
int num;
if(isempty()==1)
printf("Queue is empty ");
else
{
q->front++;
num=q->[front];
}
return num;
}

void display()
{
 int i;
 for(i=q->front;i<=q->rear;i++)
 {
  printf("%d\t",q->a[i]);
 }
}

int main()
{
 int i,num,ch;
 initq();
 do
 {
 printf("\n1-insert \n2-delete \n3-display");
 printf("enter choice");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: 
         printf("Enter value-");
         scanf("%d",&num);
         insertq(num);
         break;
 case 2:
       deleteq();
       break;
 case 3:
      display();
      break;
 }
 }while(ch<4);
}
