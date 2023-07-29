//BINARY SEARCH
//accept n numbers in array and search number using binary search 
#include<stdio.h>
int main()
{
 int a[100],i,n,num,top,mid,bottom,flag=0;
 printf("Enter limit");
 scanf("%d",&n);
 printf("Enter n numbers");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Enter number to search");
 scanf("%d",&num);
 
 top=0;
 bottom=n-1;
 while(top<=bottom)
 {
  mid=(top+bottom)/2;
  if(a[mid]==num)
  {
   flag=1;  //ONLY USE (=)SINGLE EQUAL TO SYMBOL     
   break;
   }
   if(a[mid]>num)
   {
    top=mid+1;
   }
   else
   bottom=mid-1;
 }
 
 if(flag==1)     //ONLY USE DOUBLE EQUAL TO SYMBOL
 {
  printf("Number is found");
 }
 else
 printf("Number is not found");
}

