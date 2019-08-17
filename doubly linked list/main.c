#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node*next,*prev;
    int info;
}node;
void addend(node**start)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(*start==NULL)
    {
        temp->prev=NULL;
        *start=temp;
    }
    else
    {
        node*t;
        t=*start;
        while(t->next!=NULL)
            t=t->next;
        temp->prev=t;
        t->next=temp;
    }
}
void addbeg(node**start)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(*start==NULL)
    {
        temp->prev=NULL;
        *start=temp;
    }
    else
    {
        node*t;
        t=*start;
        *start=temp;
        t->prev=temp;
        temp->next=t;
    }
}
void delbeg(node**start)
{
    if(*start==NULL)
        printf("Empty");
    else
    {
        node*t=*start;
        node*p=*start;
        t=t->next;
        *start=t;
        t->prev=NULL;
        free(p);
    }
}
void delend(node**start)
{
    if(*start==NULL)
        printf("Empty");
    else
    {
        node*t=*start;
        node*p;
        while(t->next!=NULL)
            t=t->next;
        p=t;
        t=(t->prev);
        t->next=NULL;
        free(p);

    }
}
void printnode(node*start)
{
    if(start==NULL)
        printf("Empty");
    else
    {
        node*t=start;
        while(t!=NULL)
            {
                printf("%d ",t->info);
                t=t->next;
            }
    }
}
void main()
{
    node*start=NULL;
    int n;
    while(1)
    {
        printf("\nEnter 1 to addbeg\nEnter 2 to addend\nEnter 3 to delbeg\nEnter 4 to delend\nEnter 5 to print\nEnter 99 to exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            addbeg(&start);
            break;
        case 2:
            addend(&start);
            break;
        case 3:
            delbeg(&start);
            break;
        case 4:
            delend(&start);
            break;
        case 5:
             printnode(start);
            break;
        case 99:
             exit(1);
            break;
        default:
            printf("invalid\n");
            break;
        }
    }
}
