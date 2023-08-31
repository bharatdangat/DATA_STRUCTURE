//WRITE MENU DRIVEN PROGRAM CREATE NEWNODE AND DISPLAY AND INSERT VALUE INTO BEGNING& INSERT END &INSERT     MIDDLE &DELETE BEGNING &DELETE END &DELETE MIDDLE &DELETE COMMON &INSERT COMMON" 
//ALL OPERATION...............
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{              //strcture(self referential structure)
 int data;
 struct node *next;
};

 struct node *create(struct node *head)  //datatype,function name,variable
 {
  int i,n;
  struct node *newnode,*temp;
  printf("Enter Limit-");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Value-");         //create newnode&insert value
    scanf("%d",&newnode->data);    //next null kela.
    newnode->next=NULL;
    
    if(head==NULL)       // only first time head null asto.
    {
     head=newnode;   //head ani temp la newnode la nela.
     temp=newnode;
    }
    else
    {
     temp->next=newnode;   //temp cha next newnode la jodla.
     temp=newnode;        //temp la newnode la nela.
    }
  }
    return head;   //loop chya baher yeun return head kela.
 } 
   void display(struct node *head)
   {
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
      printf("%d\t",temp->data);
    }
   }
   
    //1]-
    struct node *insertbeg(struct node *head,int num)
    {
     struct node *newnode;
     newnode=(struct node *)malloc(sizeof(struct node));
     newnode->data=num;
     newnode->next=head;
     head=newnode;
     return head;
    }
    //2]-
    struct node *insertend(struct node *head,int num)
    {
     struct node *newnode,*temp;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=num;
     newnode->next=NULL;
     for(temp=head;temp->next!=NULL;temp=temp->next);
     temp->next=newnode;
     return head;
    }
    //3}-
    struct node *insertmiddle(struct node *head,int num,int pos)
    {
     struct node *newnode,*temp;
     int i;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=num;
     for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
     newnode->next=temp->next;   //( ) BRACKET IMPPPPPPPPPP
     temp->next=newnode;
     return head;
    }
    //4]-
     struct node *delbeg(struct node *head)
     {
      struct node *temp;
      temp=head;
      head=head->next;
      free(temp);
      return(head);
     }
     //5]-
      struct node *delend(struct node *head)
      {
       struct node *newnode,*temp,*temp1;
       for(temp=head;temp->next->next!=NULL;temp=temp->next);
       temp1=temp->next;//OR for(temp1=head;temp1!=NULL;temp1=temp1->next);
       temp->next=NULL;
       free(temp1);
       return head;
      }
      //6]-
       struct node *delmid(struct node *head,int pos)
       {
        int i;
        struct node *temp,*temp1;
        for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        return(head);
       }
       //7]-
       struct node *delete(struct node *head,int pos)
       {
        struct node *temp,*temp1;
        int i;
        if(pos==1)
        {
         temp=head;               //LOGIC DELETE BEGNING......
         head=head->next; 
         free(temp);
        }
        else
        {
          for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);  
          temp1=temp->next;        //LOGIC DELETE MIDDLE.......
          temp->next=temp1->next;
          free(temp1);
        }
        return head;
       }
       //8]-
       struct node *insert(struct node *head,int num,int pos)
       {
        struct node*newnode,*temp;
        int i;
        if(pos==1)
        {
         newnode=(struct node*)malloc(sizeof(struct node));
         newnode->data=num;          //LOGIC DELETE BEGNING......
         newnode->next=head;
         head=newnode;
        }
        else
        {
          for(i=1,temp=head;i<(pos-1),temp->next!=NULL;i++,temp=temp->next);  
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data=num;  //LOGIC DELETE BEGNING......
          newnode->next=temp->next;
          temp->next=newnode;
        }
        return head;
       }
   int main()
   {
   int ch,num,pos;
   struct node *head=NULL;
  do
  {
   printf("\n1-:CREATE \n2-:DISPLAY \n3-:INSERT BEG \n4-:INSERT END \n5-:INSERT     MIDDLE \n6-:DELETE BEG \n7-:DELETE END \n8-:DELETE MIDDLE \n9-:DELETE COMMON \n10-:INSERT COMMON");
   printf("\nEnter Choice-:");
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
          printf("Enter Number to insert beg=>>");
          scanf("%d",&num);
          head=insertbeg(head,num);
          break;
    case 4:
          printf("Enter No to insert end=>> ");
          scanf("%d",&num);
          head=insertend(head,num);
          break;
    case 5:
          printf("Enter No to insert middle=>> ");
          scanf("%d",&num);
          printf("Enter Position=");
          scanf("%d",&pos);
          head=insertmiddle(head,num,pos);
          break;
   case 6:
        head=delbeg(head);
        break;
  case 7:
       head=delend(head);
       break;
  case 8:
       printf("Enter middle Position to delete-");
       scanf("%d",&pos);
       head=delmid(head,pos);
       break;
  case 9:
       printf("Enter Position-");
       scanf("%d",&pos);
       head=delete(head,pos);
       break;
  case 10:
       printf("Enter Number=");
       scanf("%d",&num);
       printf("Enter Position-");
       scanf("%d",&pos);
       head=insert(head,num,pos);
       break;  
   }
  }while(ch<11);
}
