//accept n city names and std code from user and accept city name from user and use binarysearch  algorithm to check whether name is present or not

#include<stdio.h>
#include<string.h>
struct cities
{
  int stdcode;
  char cname[20];
}c1[100];
int main()
{
 int i,n;
 char name[20];
 void search(struct cities c1[100],char name[20],int n);
 printf("enter limit");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter STD code  City Name IN SORTED ORDER");
 scanf("%d%s",&c1[i].stdcode,c1[i].cname);
 }
 printf("Enter City to search");
 scanf("%s",name);
 
  search(c1,name,n);
}//end of main()

void search(struct cities c1[100],char name[20],int n)
{
  int i,top,bottom,mid,flag=0;
  
  top=0;
  bottom=n-1;
  while(top<=bottom)
  {
   mid=(top+bottom)/2;
   if(strcmp(c1[mid].cname,name)==0)
   {
    flag=1;
    break;
    }
    if(strcmp(c1[mid].cname,name)<0)
    {
     top=mid+1;
    }
    else
    bottom=mid-1;
  }//end of while
  
  if(flag==1)
    printf("Name is present");
  else
  printf("Name is not present");
}//end of function


