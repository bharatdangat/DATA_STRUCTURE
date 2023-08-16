//MENU DRIVEN PROGRAM OF LINEAR,SENTINAL AND BINARY SEARCH.

#include<stdio.h>

 void linear(int a[100],int num,int n)
 {
 int i,flag=0;
  for(i=0;i<n;i++)
  {
   if(a[i]==num)
   {
    flag=1;  
    break;
   }
  }
  if(flag==1)
  {
   printf("Number is found psition=%d",i);
   }
   else
   printf("Number is not found");
  }
  
  int sentinal(int a[100],int num,int n)
  {
   int i=0,p;
  a[n]=num;
  while(a[i]!=num)
  {
   i++;
  }
  if(i==n)
  {                   
   return -1;    
   }
   else
{
   return i;
 }
}

void binary(int a[100],int num,int n)
{
 int i,flag=0;
 int top,bottom,mid;
 top=0;
 bottom=n-1;
 while(top<=bottom)
 {
  mid=(top+bottom)/2;
  if(a[mid]==num)
  {
   flag=1;
   break;
  }
  if(a[mid]<num)
  top=mid+1;
  else
  bottom=mid-1;
 }
 if(flag==1)
 {
 printf("\nNumber is found position=%d",mid);
 }
 else
 printf("Number is not found");
}


int main()
{
   int a[100],i,n,num,ch,p;
   printf("Enter limit");
   scanf("%d",&n);
   printf("Enter n numbers in sorted order");
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
   printf("Enter number to search");
   scanf("%d",&num);
   do
   {
    printf("\n1-Linear search \n2-sentinal search \n3-Binary Search");
    printf("\nEnter Your Choice-");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:linear(a,num,n);
            break;
      case 2:p=sentinal(a,num,n);
             
             if(p==-1)
             {      
               printf("NUMBER is not found ");
             } 
             else
             {
                printf("\nNUMBER is Found position=%d",p);
              }
             break;
             
        case 3:binary(a,num,n);
               break;
    }
}while(ch<4);
}
