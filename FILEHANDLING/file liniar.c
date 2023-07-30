//SEARCH GIVEN NUMBER FROM ''nunbers.txt''FILE USING LINIAR SEARCH.
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int x,num,flag=0;
  FILE *fp1;      //declare
  fp1=fopen("numbers.txt","r"); //open
  if(fp1==NULL)
  {
   printf("file is not found");
   exit(0);                         //x=accept no 
  }                                 //to search
                                    //num=from file 
   printf("Enter number to search");
   scanf("%d",&x);
  while(!feof(fp1))
  {
    fscanf(fp1,"%d",&num);
 
       if(num==x)
       {
        flag=1;
        break;
       }
   }
   
  if(flag==1)
printf("number is found");
      else
     printf("number is not found");
   
  fclose(fp1);
}


