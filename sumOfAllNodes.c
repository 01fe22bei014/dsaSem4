#include<stdio.h>
#include<stdlib.h>



struct listNode
{
    int value;
    struct listNode *next;

};


int sumOfAllNodes(struct listNode *head)
{
    struct listNode *current=head;

    int totalSum=0;
    while(current!=NULL)
    {
        totalSum+=current->value;
        current=current->next;

    }
    return totalSum;

}


int main()
{
    int numberOfNodes;
    printf("enter number of nodes");
    scanf("%d",&numberOfNodes);


    struct listNode *head=NULL;
    struct listNode *tail=NULL;


    for (int i=0 ;  i < numberOfNodes ; i++)
    {
        int value;
        printf("enter value of node number %d   ",i+1);
        scanf("%d",&value);

        struct listNode *newnode=(struct listNode*)malloc(sizeof(struct listNode));

        newnode->value=value;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;


        }
        else
        {
            tail->next=newnode;
             tail=newnode;


        }

    }

    int total=sumOfAllNodes(head);
    printf("sum is %d",total);




}
