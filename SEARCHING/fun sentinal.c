//SENTINAL SEARCH=>using funcion
   #include<stdio.h>
   int main()
  {
  int a[100],i,n,key,p;
  int sentinal(int a[100],int key,int n);
  printf("Enter limit");
  scanf("%d",&n);
  printf("enter n numners");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }                                // AFTER WHILE LOP USE I=0;
  printf("enter no to search");
  scanf("%d",&key);
 
 p=sentinal(a,key,n);
 if(p==-1)
{      
 printf("NUMBER is not found ");
} 
else
{
 printf("NUMBER is Found position=%d",p);
}
 }
 int sentinal(int a[100],int key,int n)
 {
int i=0;
  a[n]=key;
  while(a[i]!=key)
  {
   i++;
  }
  if(i==n)
  {                    //rerurn -1 kelyavar lagech main madhe jaun call hoto(pudhch execute hot nahi) mhanun print karatani pahile p=-1 
                      // ghetle.not p==i .
   return -1;    
   }
   else
{
   return i;
 }
}


