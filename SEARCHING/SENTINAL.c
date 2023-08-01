   //SENTINAL SEARCH=>
   #include<stdio.h>
    int main()
    {
  int a[100],i,n,key,flag=0;
  printf("Enter limit");
  scanf("%d",&n);
  printf("enter n numners");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }                                // AFTER WHILE LOP USE I=0;
  printf("enter no to search");
  scanf("%d",&key);

  a[n]=key;
 i=0;
  while(a[i]!=key)
{
 i++;
}
  if(i==n)
  printf("Not Found");
else
printf("Found position=%d",i);
  }


