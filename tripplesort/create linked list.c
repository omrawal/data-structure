#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
struct node*start=NULL;
struct node*createnode()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return(temp);
}
void insertnode()
{
     struct node*t,*temp;
     temp=createnode();
      printf("Enter Data ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        t=start;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}
int main()
{
    int i,n;struct node*t;
    printf("Enter the number of ele. in list\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        insertnode();
    printf("The list is \n");
    t=start;
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t=t->link;
    }

    return 0;
}
