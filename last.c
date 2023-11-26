#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct Queue
{
 int data[MAX];
 int front,rear;
}*q;

void initq()
{
 q=(struct Queue*)malloc(sizeof(struct Queue));       //MEMORY ALLOCATION........
 q->front=-1;
 q->rear=-1;
}

int isempty()
{
 if(q->front==-1||q->front>q->rear)
 {
 return 1;
 }
 else
  return 0;
}

int isfull()
{
 if(q->rear==MAX-1)
 {
  return 1;
 }
 else
 return 0;
}

void insertq(int num)
{
 if(isfull())
 printf("Queue is overflow.................");
 else
 {
    if("q->front==-1");
    {
    q->front=0;               //CONDITION IS NOT NECESSARY..............
    }
  q->rear++;
  q->data[q->rear]=num;
  printf("Insert Succ........");
 }
}

void deleteq()
{
 int val;
 if(isempty())
 printf("Queue is underflow............");
 else
 {
  val=q->data[q->front];
  q->front++;
  printf("Deleted value=%d",val);
 }
}
void disp()
{
 int i;
 if(isempty())
 printf("Queue is underflow......");
 
 for(i=q->front;i<=q->rear;i++)
 {
  printf("%d\t",q->data[i]);
 }
}

int main()
{
 int i,ch,num;
 initq();
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
        insertq(num);
break;
  case 2:
        deleteq();
        break;
        //...............................OR....................................................................................>
        /*case 2:
        val=deleteq();
        printf("Deleted value is =%d",val);
        break;  */
  
  case 3:
       disp();
       break;
  }
 }while(ch<4);
}


