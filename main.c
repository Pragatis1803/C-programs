/*#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;
NODE * insert(NODE *first,int data)
{
    NODE *newnode,*temp;
    newnode = (NODE*)malloc(sizeof(NODE));

    newnode->info = data;
    newnode->next = NULL;

    if(first == NULL)
        first=newnode;
    else
    {
        temp = first;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("\n%d is inserted into list",data);
    return(first);
 }
 NODE* segregate(NODE *first)
 {
     NODE *temp,*end,*end1;
     NODE *temp1,*prev=NULL;
     int flag=0;
     if(first==NULL)
     {
         printf("\nEmpty List\n");
         return first;
     }
     temp=first;
     end=first;
    while(end->next!=NULL)
        end=end->next;
    end1=end;
    while(temp!=end)
    {
        if(temp->info%2!=0)
        {
            temp1=temp->next;
            end1->next=temp;
            if(prev!=NULL)
                prev->next=temp->next;
            end1->next->next=NULL;
            end1=end1->next;
            temp=temp1;
        }
        else
        {
            if(flag==0)
            {
                first=temp;
                flag=1;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    if(temp==end && end->info%2!=0)
    {
        end1->next=temp;
        if(prev!=NULL)
            prev->next=temp->next;
        end1->next->next=NULL;
        end1=end1->next;
    }
    printf("The list is segregated successfully.\n");
    return first;
 }
 void display(NODE *first)
{
    if(first == NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    printf("\nList Contents:\nBegin->");
    while(first!=NULL)
    {
        printf("%d->",first->info);
        first = first ->next;
    }
    printf("End");
}
 int main()
{
    NODE *first=NULL;
    int choice,data;

    while(1)
    {
        printf("\n\n1:Insert\n2:Segregate\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the data to be inserted: ");
                    scanf("%d",&data);
                    first=insert(first,data);
                    break;
            case 2: first=segregate(first);
                    break;
            case 3: display(first);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}*/
//Method 2
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;
NODE * insert(NODE *first,int data)
{
    NODE *newnode,*temp;
    newnode = (NODE*)malloc(sizeof(NODE));

    newnode->info = data;
    newnode->next = NULL;

    if(first == NULL)
        first=newnode;
    else
    {
        temp = first;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return(first);
 }
  void display(NODE *first)
{
    if(first == NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    printf("\nList Contents:\nBegin->");
    while(first!=NULL)
    {
        printf("%d->",first->info);
        first = first ->next;
    }
    printf("End");
}
 void segregate(NODE *first)
 {
     NODE *segregatedList=NULL;
     NODE *temp;
     temp=first;
     while(temp!=NULL)
     {
         if(temp->info%2==0)
            segregatedList=insert(segregatedList,temp->info);
         temp=temp->next;
     }
     temp=first;
     while(temp!=NULL)
     {
         if(temp->info%2!=0)
            segregatedList=insert(segregatedList,temp->info);
         temp=temp->next;
     }
     printf("\nSegregated List: \n");
     display(segregatedList);
 }

 int main()
{
    NODE *first=NULL;
    int choice,data;

    while(1)
    {
        printf("\n\n1:Insert\n2:Segregate\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the data to be inserted: ");
                    scanf("%d",&data);
                    first=insert(first,data);
                    printf("\n%d is inserted into list",data);
                    break;
            case 2: segregate(first);
                    break;
            case 3: display(first);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}


