//accept n city names and std code from user and accept city name from user and use linear searxh algorithm to check whether name is present or not [using function]
#include<stdio.h>
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
 printf("Enter limit ");
 scanf("%d",&n);

for(i=0;i<n;i++)
{
 printf("Enter STD code  city name ");
 scanf("%d%s",&c1[i].stdcode,c1[i].cname);
}
 printf("Enter city to search");
 scanf("%s",name);
 
 search(c1,name,n);
}
void search(struct cities c1[100],char name[20],int n)
{ 
 int i;
 for(i=0;i<n;i++)
 {
  if(strcmp(c1[i].cname,name)==0)
  {
    printf("Name is found");
    break;
  }
    if(i==n)
    {
    printf("Name is not found");
    }
 }
 




