#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node*link;
    int info;
}node;
void push(node**start)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(*start==NULL)
        *start=temp;
    else
    {
        node*t;
        temp->link=*start;
        *start=temp;
    }

}

void pop(node**start)
{
    if(*start==NULL)
        printf("stack is empty\n");
    else
    {
        node*p=*start;
        node*t=*start;
        t=t->link;
        *start=t;
        printf("popped element is: %d",p->info);
        if(p->link==NULL)
            *start==NULL;
        free(p);
    }
}

void print(node*start)
{
    if(start==NULL)
        printf("stack is empty\n");
    else
    {
        while(start!=NULL)
        {
            printf("%d ",start->info);
            start=start->link;
        }
    }
}
int main()
{
    node*start=NULL;
    int n;
    while(1)
    {
        printf("\nEnter 1 to PUSH\nEnter 2 to POP\nEnter 3 to view stack\nEnter 99 to exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                push(&start);
                break;
            case 2:
                pop(&start);
                break;
            case 3:
                print(start);
                break;
            case 99:
                exit(1);
                break;
            default:
                printf("invalid\n");
                break;

        }
    }
    return 0;
}
