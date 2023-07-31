//READ DATA FROM FILE "cities.txt" CONTAN STD CODE AND CITIES NAME.ACCEPT NAME OF CITy FROM USER BY USING BINARY SEARCH ALGORITHM TO CHECK NAME IS PRESENT.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cities
{
   int STD_code;
   char cname[20];
}c1[100];
int main()
{
  int i=0,n,top,bottom,mid,flag=0,code;
  char city[20],x[20];
  FILE *fp1;  //declare
  fp1=fopen("sorted cities.txt","r"); //open
  if(fp1==NULL)          //check
  {
    printf("file is not found");
    exit(0);         //code=store in file
  }                   //city=store in file
  while(!feof(fp1))
  {
  fscanf(fp1,"%d%s",&code,city);    //Read
          c1[i].STD_code=code;               //NOT USE STRCPY BECOZ INT VALUE COMPARE
   strcpy(c1[i].cname,city);
   i++;
   //structure madhale element fil chya 
  //variable madhe store kele.
  }
  n=i;   //(LIMIT) I MADHUN N MADHE GHETLE
  printf("Enter City Name to Search ");
  scanf("%s",x);      //NOT USE &
  
  top=0;               //main logic
   bottom=n-1;
   while(top<=bottom)
   {
     mid=(top+bottom)/2;
      if(strcmp(c1[mid].cname,x)==0)
      {
       flag=1;
       break;
      }
      if(strcmp(c1[mid].cname,x)<0)
       top=mid+1;
      else
       bottom=mid-1;
 }
   if(flag==1)
   printf("City is found STD code=%d",c1[mid].STD_code);
   else
   printf("City is Not Found in the List");
  
     fclose(fp1);
}

