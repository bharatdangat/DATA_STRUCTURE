//BINARY SEARCH(using function)
//By Using Function accept n numbers in array and search number using binary search 
#include<stdio.h>
int main()
{
int a[100],i,n,num;
void search(int a[100],int num,int n);
printf("Enter limit");
scanf("%d",&n);
printf("Enter n numbers in sorted order");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
printf("Enter number to search");
scanf("%d",&num);

search(a,num,n);
}

void search(int a[100],int num,int n)
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
 printf("Number is found");
 }
 else
 printf("Number is not found");
}


