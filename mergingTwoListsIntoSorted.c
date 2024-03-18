#include<stdio.h>
#include<stdlib.h>
int num1,num2;

struct node
{
    int data;
    struct node *next;

};
struct node* swapNodes(struct node* list1, struct node* list2) {
    if (list1 == NULL || list2 == NULL) {
        printf("Invalid input: Both nodes must be non-null.\n");
        return NULL;
    }

    // Find the previous nodes of list1 and list2
    struct node* prev1 = NULL;
    struct node* curr1 = list1;
    while (curr1 != NULL && curr1 != list2) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    struct node* prev2 = NULL;
    struct node* curr2 = list2;
    while (curr2 != NULL && curr2 != list1) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // If either node is not found, return
    if (curr1 == NULL && curr2 == NULL) {
        printf("Both nodes not found in the list.\n");
        return NULL;
    }

    // Swap the next pointers of the previous nodes
    if (prev1 != NULL) {
        prev1->next = list2;
    } else {
        list1 = list2;
    }

    if (prev2 != NULL) {
        prev2->next = list1;
    } else {
        list2 = list1;
    }

    // Swap the next pointers of the nodes themselves
    struct node* temp = list1->next;
    list1->next = list2->next;
    list2->next = temp;

    return list1;
}


void recDisplay(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d",temp->data);
        recDisplay(temp->next);
    }

}

struct Node *createLinkedList(int size)
{
    //int numOfNodes;
    //printf("Enter the number of nodes: ");
    //scanf("%d", &numOfNodes);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
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

struct node *sortLists(struct node *list1,struct node *list1)
{
    struct node *first1=list1;
    struct node *first2=list2;
    while(first1!=NULL && first2!=NULL)
    {
        for(int i=0;i<num1;i++)
        {
            if(first1->data>first1->next->data)
            {
                struct node *sortedlist1=swapNodes(first1,first1->next);
                first1=first1->next;
            }
        }

    }

};

int main()
{

    printf("enter num of elements in list 1 ");
    scanf("%d",num1);
    struct node *LL1=createLinkedList(num1);
    recDisplay(LL1);

    printf("enter num of elements in list 2 ");
    scanf("%d",num2);
    struct node *LL2=createLinkedList(num1);
    recDisplay(LL2);


}
