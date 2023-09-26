//WRITE MENU DRIVEN PROGRAM IN DOUBLY LINKED LL. CREATE NEWNODE AND DISPLAY AND INSERT VALUE INTO BEGNING& INSERT END &INSERT     MIDDLE &DELETE BEGNING &DELETE END &DELETE MIDDLE &DELETE COMMON &INSERT COMMON AND SEARCH GIVEN NO....................." 
//ALL OPERATION...............

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
 int data;
 struct node *next,*prev;
};

struct node *create(struct node *head)
{
 int i,n;
 struct node *newnode,*temp;
 printf("Enter Limit-");
 scanf("%d",&n);
for(i=0;i<n;i++)
{
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("Enter Value-");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 if(head==NULL)
 {
  head=newnode;
  temp=newnode;
 }
 else
 {
  temp->next=newnode;
  newnode->prev=temp;
  temp=newnode;
 }
}
return head;
}
void display(struct node *head)
{
 struct node*temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 {
  printf("%d\t",temp->data);
 }
}

//1
  struct node *insertbeg(struct node *head,int num)
  {
   struct node *newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=head;
   head->prev=newnode;
   head=newnode;
   return head;
  }
//2
 struct node* insertmid(struct node*head,int num,int pos)
 {
  struct node*newnode,*temp;
  int i;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=num;
  for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
  newnode->next=temp->next;
  temp->next->prev=newnode;
  temp->next=newnode;
  newnode->prev=temp;
  return head; 
 }
 
 struct node* insertend(struct node *head,int num)
 {
  struct node*newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=num;
  newnode->next=NULL;
  for(temp=head;temp->next!=NULL;temp=temp->next);
  temp->next=newnode;
  newnode->prev=temp;
  return head;
 }
 
 struct node* delbeg(struct node* head)
 {
  struct node *temp;
  temp=head;
  head=head->next;
  free(temp);
  return head;
 }
 
 struct node *delend(struct node* head)
 {
  struct node *temp,*temp1;
  for(temp=head;temp->next->next!=NULL;temp=temp->next);
  temp1=temp->next;
  temp->next=NULL;
  free(temp1);
  return head;
 }
 
 struct node *delmid(struct node* head,int pos)
 {
  struct node *temp,*temp1;
  int i;
  for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
  temp1=temp->next;
  temp->next=temp1->next;
  temp1->next->prev=temp;   //NOT TEMP->NEXT 
  free(temp1);
  return head;
 }
 
 
 struct node *insert(struct node*head,int num,int pos)
 {
  struct node*newnode,*temp;
  int i;
  if(pos==1)
  {
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=head;
   head->prev=newnode;
   head=newnode;
  }
  else
  {
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
    newnode->next=temp->next;
    newnode->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
  }
  return head;
 }
 
 struct node *delete(struct node*head,int pos)
 {
  struct node*newnode,*temp,*temp1;
  int i;
  if (pos==1)
  {
   temp=head;
   head=head->next;
   free(temp);
  }
  else
  {
   for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
    temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    free(temp1);
  }
 return head;
 }
int main()
{
 int i,ch,num,pos;
 struct node*head=NULL;
 do
 {
  printf("\n1-CREATE \n2-DISPLAY \n3-INSERT BEG \n4-INSERT MID \n5-INSERT END \n6-DELETE BEG \n7-DELETE END \n8-DELETE MID \n9-INSERT(COMMON) \n10-DELETE(COMMON)");
  printf("\nEnter Choice-");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
        head=create(head);
        break;
  case 2:
       display(head);
       break;
  case 3:
       printf("Enter Number to insert beg-");
       scanf("%d",&num);
       head=insertbeg(head,num);
       break;
  case 4:
       printf("Enter Number to insert mid-");
       scanf("%d",&num);
       printf("Enter Position");
       scanf("%d",&pos);
       head=insertmid(head,num,pos);
       break;
  case 5:
       printf("Enter Number to insert end-");
       scanf("%d",&num);
       head=insertend(head,num);
       break;
  case 6:
       head=delbeg(head);
       break;
  case 7:
       head=delend(head);
       break;
  case 8:
      printf("Enter Position for delete-");
      scanf("%d",&pos);
       head=delmid(head,pos);                 //START LA HEAD GHENE IMP ALL OPERATION..............
       break;
  case 9:
       printf("Enter Number-");
       scanf("%d",&num);
       printf("Enter Pos");
       scanf("%d",&pos);
       head=insert(head,num,pos);
       break;
  case 10:
       printf("Enter Position to delete-");
       scanf("%d",&pos);
       head=delete(head,pos);
       break;
  }
 }while(ch<11);
}







