#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;
struct node * createLinkedList(int n); 
void print(); 
void particularinsert(); 
void particular_delete();  
void main()

{
int n=0;
      struct node * HEAD=NULL;
      
       printf("\n How many nodes:");
       scanf("%d",&n);
       HEAD=createLinkedList(n);
       print(HEAD);
       particularinsert(HEAD);
       print(HEAD);
       particular_delete(HEAD);
       print(HEAD);
       

}
struct node * createLinkedList(int n)

{
    int i=0;
    struct node *head=NULL; 
    struct node *temp=NULL;
    struct node *p=NULL;
    for(i=1;i<=n;i++)
    {
      temp=(struct node *)malloc(sizeof( struct node));
      printf("\n Enter the data for %d node number:",i);
      scanf("%d",&(temp->data));
      temp->next=NULL;
      if(head == NULL)
      {
         head=temp;
      }
      else
      {
          p=head;
          while(p->next!=NULL)
             p=p->next;
          p->next= temp;
      
      }
    }
    return head;
    
}

void particularinsert(struct node * head)  
{  
    int i,loc,item;   
    struct node *n, *temp;  
    n = (struct node *) malloc (sizeof(struct node));  
    if(n == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value\t:");  
        scanf("%d",&item);  
        n->data = item;  
        printf("\nEnter location on inserted node ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert!!!!\n");  
                return;  
            }  
          
        }  
        n ->next = temp ->next;   
        temp ->next = n;   
        printf("\nNode inserted!!!");  
    }  
}
void particular_delete(struct node *head)  
{  
    struct node *p,*p1;  
    int loc,i;    
    printf("\n Enter the location to delete  :\n");  
    scanf("%d",&loc);  
    p=head;  
    for(i=0;i<loc;i++)  
    {  
        p1 = p;       
        p = p->next;  
              
        if(p == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    p1 ->next = p ->next;  
    free(p);  
    printf("\nDeleted location is %d and deleted node is %d ",loc,loc+1);  
}      
void print(struct node * head)  
{  
    struct node *n;  
    n = head;   
    if(n == NULL)  
    {  
        printf("Nothing to print!!!!!!");  
    }  
    else  
    {  
        printf("\nnew linked list is ........:\n");   
        while (n!=NULL)  
        {  
            printf("\t%d",n->data);  
            n = n -> next;  
        }  
    }  
}     
