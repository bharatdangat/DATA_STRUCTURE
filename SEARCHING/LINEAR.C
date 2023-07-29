#include<stdio.h>
int main()
{
  int a[100],i,n,num,flag=0;
  printf("Enter limit");
  scanf("%d",&n);
  printf("enter n numners");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }                                /*IMP NOTE NOT USE = = IN LINE 18*/
  printf("enter no to search");
  scanf("%d",&num);
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
   printf("Number is found");
   }
   else
   printf("Number is not found");
  
}
