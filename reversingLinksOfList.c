#include<stdio.h>
#include<stdlib.h>


struct node
{

    int data;
    struct node *next;
};

struct node *createLinkedList()
{
    int numOfnodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numOfnodes);

    struct node *head = NULL;
    struct node *tail = NULL;

    for (int i = 0; i < numOfnodes; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode != NULL)
        {
            printf("Enter data for node %d: ", i + 1);
            scanf("%d", &newnode->data);
            newnode->next = NULL;

            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }
        else
        {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    return head;
}




struct node *revLinkList(struct node *first)
{
    struct node *r,*q,*p;
    p=first;
    r=q=NULL;
    while(p!=NULL)
    {
    r=q;
    q=p;
    p=p->next;
    q->next=r;



    }
    first=q;
    return first;



}

void recDisplay(struct node *temp)
{
    if(temp!=NULL)
    {

        printf("%d ",temp->data);
        recDisplay(temp->next);
    }

}

int main()
{


    struct node *t=createLinkedList();
    printf("orignal list is : \n");

    recDisplay(t);
     printf("\n");
    struct node *y=revLinkList(t);
    printf("reverse linked list is  : \n");
    recDisplay(y);
}
