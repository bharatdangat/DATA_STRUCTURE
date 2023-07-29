//BINARY SEARCH(USING FUNCTION)
//USING STRUCTURE
//Q].-CREATE STRUCTURE STUDENT AND ACCEPT N STUDENT INFORMATION ACCEPT STUDENT NAME TO SEARCH BY USING FUNCTION.USING TECHNIQUE BINARY SEARCH.
#include<stdio.h>
#include<string.h>
struct student
{
  int rno;
  char sname[20];
  float per;
}s1[100];
int main()
{
int i,n;
char name[20];
void search(struct student s1[100],char name[20],int n);
printf("Enter limit");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Student Roll No Name Per in ASCENDING ORDER");
scanf("%d%s%f",&s1[i].rno,s1[i].sname,&s1[i].per);
}

printf("Enter Student Name to search");
scanf("%s",name);

search( s1,name,n);
}

void search(struct student s1[100],char name[20],int n)
{
 int i,flag=0;
 int top,bottom,mid;
 top=0;
 bottom=n-1;
 while(top<=bottom)
 {
  mid=(top+bottom)/2;
  if(strcmp(s1[mid].sname,name)==0)
  {
   flag=1;
   break;
  }
  if(strcmp(s1[mid].sname,name)<0)
  top=mid+1;
  else
  bottom=mid-1;
 }
 if(flag==1)
 {
 printf("Name is found");
 printf("Student Information=");
 printf("Student ROll No=%d",s1[mid].rno);
 printf("Student  Name=%s",s1[mid].sname);
 printf("Student Per=%f",s1[mid].per); 
 }
 else
 printf("Name is is not found ...............");
}



