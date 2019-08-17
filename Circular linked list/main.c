#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *link;

}node;
void addbeg(node**start,node**end)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->info);
    if(*start==NULL)
        {
            *start=temp;
            *end=temp;
            temp->link=*start;
        }
    else
    {
        node*p;
        temp->link=*start;
        *start=temp;
        p=*end;
        p->link=temp;
    }
}
void addend(node**start,node**end)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->info);
    if(*start==NULL)
        {
            *start=temp;
            *end=temp;
            temp->link=*start;
        }
    else
    {
        node*p=*end;
        p->link=temp;
        temp->link=*start;
        *end=temp;
    }
}
void delbeg(node**start,node**end)
{
    if(*start==NULL)
        printf("Empty\n");
    else
        {
           node*p=*start;
           *start=p->link;
           node*t=*end;
           t->link=*start;
           free(p);
        }

}
void delend(node**start,node**end)
{
    if(*start==NULL)
        printf("Empty\n");
    else
        {
           node*p=*end;
           node*t=*start;
           while(t->link!=*end)
            t=t->link;
           t->link=*start;
           free(p);
        }
}

void print(node*start,node*end)
{
    if(start==NULL)
        printf("Empty\n");
    else
    {
        node*p=start;
        do
        {
            printf("%d ",p->info);
            p=p->link;
            //printf("%d ",p->info);
        }while(p!=start);
    }
}
int main()
{
    node*start=NULL,*end=NULL;
    int n;
    while(1)
    {
        printf("\nEnter 1 to addbeg\nEnter 2 to addend\nEnter 3 to print\nEnter 4 to delbeg\nEnter 5 to delend\nEnter 99 to exit\n");
        scanf("%d",&n);
        switch(n)
            {
        case 1:
            addbeg(&start,&end);
            break;
        case 2:
            addend(&start,&end);
            break;
        case 3:
            print(start,end);
            break;
        case 4:
            delbeg(&start,&end);
            break;
        case 5:
            delend(&start,&end);
            break;
        case 99:
            exit(1);
            break;
        default:
            printf("invalid");
            break;
            }
    }
    return 0;
}
