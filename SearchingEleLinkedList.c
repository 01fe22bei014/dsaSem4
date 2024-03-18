#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;

};



struct Node *createLinkedList() {
    int numberOfNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < numberOfNodes; i++)
    {
        int data;
        printf("Enter data of node number %d: ", i + 1);
        scanf("%d", &data);

        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        newnode->data = data;
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

    return head;
}


struct Node * search(struct Node*temp,int key)
{
    while(temp!=0)
    {
        if(temp->data==key)
        {
            return temp;
        }
        temp=temp->next;


    }
    return NULL;

};


int main()
{
    struct Node *head=createLinkedList();
    int searchkey;
    printf("enter key");
    scanf("%d",&searchkey);


    struct Node *result=search(head,searchkey);

    if(result!=NULL)
    {

        printf(" found %d",searchkey);
    }
    else{
        printf("not found  %d",searchkey);
    }

}
