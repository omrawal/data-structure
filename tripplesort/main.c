#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node*link;
}node;
void addend(node**start)
{
    node*temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(*start==NULL)
        *start=temp;
    else
    {
        t=*start;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}
void addbeg(node**start)
{
    node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(*start==NULL)
        *start=temp;
    else
    {
        temp->link=*start;
        *start=temp;
    }
}
void addmid(node**start)
{
    node*temp,*t,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->info);
    printf("Enter element after which you want to add: ");
    int key;
    scanf("%d",&key);
    t=*start;
    while(t!=NULL)
    {
        if(t->info==key)
        {
            p=t->link;
            t->link=temp;
            temp->link=p;
        }
        t=t->link;
    }
}
void deleteend(node**start)
{
    node*t,*p;
    if(*start==NULL)
        printf("The list is Empty\n");
    else
    {
        t=*start;
        if(t->link==NULL)
            *start=NULL;
        else
        {
        while(t->link!=NULL)
        {
            p=t;
            t=t->link;
        }
        p->link=NULL;
        }
        free(t);
    }
}
void deletebeg(node**start)
{
    node*t,*p;
    t=*start;
    if(t==NULL)
    printf("List is empty\n");
    else if(t->link==NULL)
    {
        free(t);
        *start=NULL;
    }
    else
    {
        p=t;
        t=t->link;
        *start=t;
        free(p);
    }
}
void sortnode(node**start)
{
    node *t,*a;
    t=*start;
    int count=0,i,temp;
    while(t!=NULL)
    {
        t=t->link;
        count++;
    }
    t=*start;
    for(i=0;i<count;i++)
    {
          while(t->link!=NULL)
        {
            a=t;
            t=t->link;
            if(a->info>t->info)
            {
                temp=a->info;
                a->info=t->info;
                t->info=temp;
            }
        }
        t=*start;
    }
}
void deletemid(node**start)
{
    node *t,*p,*a;
    int n;
    t=*start;
    p=*start;
    printf("Enter element to delete\n");
    fflush(stdin);
    scanf("%d",&n);
    if(t==NULL)
    printf("List is empty\n");
    else
    {
        while(t->info!=n)
            t=t->link;
            a=t;
                while(p->link!=t)
                    p=p->link;
                p->link=t->link;
                free(a);
    }
}
void printnode(node*start)
{
    if(start==NULL)
        printf("List is empty\n");
    else
    {
        while(start!=NULL)
        {
            printf("%d ",start->info);
            start=start->link;
        }
    }
}
void reverselist(node**start)
{
    node *current,*link=NULL,*prev=NULL;
    current=*start;
    while(current!=NULL)
    {
        link=current->link;
        current->link=prev;
        prev=current;
        current=link;
    }
    *start=prev;
}
/*void concatelist(node**start1,node**start2)
{
    int n1,n2,i;
    node*t;
    printf("Enter the number of elements in first list: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    addend(start1);
    printf("Enter the number of elements in second list: ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    addend(start2);
    t=*start1;
    while(t!=NULL)
        t=t->link;
    t->link=*start2;
    printf("The concatinated list is :- \n");
    t=*start1;
    while(t!=NULL)
      {
         printf("%d",t->info);
         t=t->link;
      }
}*/
void main()
{
    int choice;
    struct node*start=NULL,*start1=NULL,*start2=NULL;
    while(1)
    {
        printf("\nEnter 1 to add element to end of list\nEnter 2 to add element to beg of list\nEnter 3 to add element to specified pos. of list\nEnter 4 to print list\nEnter 5 to delete end\nEnter 6 to delete beginning\nEnter 7 to delete specific element\nEnter 8 to sort element\nEnter 9 to reverse list\nEnter 99 to exit\n");
        scanf("%d",&choice);
        switch(choice)
            {
            case 1:
                addend(&start);
                break;
            case 2:
                addbeg(&start);
                break;
            case 3:
                addmid(&start);
                break;
            case 4:
                printnode(start);
                break;
            case 5:
                deleteend(&start);
                break;
            case 6:
               deletebeg(&start);
                break;
            case 7:
                deletemid(&start);
                break;
            case 8:
                sortnode(&start);
                break;
            case 9:
                reverselist(&start);
                break;
            case 10:
                //concatelist(&start1,&start2);
                break;
            case 11:
                //intersectlist(&start1,&start2);
                break;
            case 99:
                exit(1);
                break;
            default:
                printf("Invalid input!!\n");
                break;
            }
    }
}
