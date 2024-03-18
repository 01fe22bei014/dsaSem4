#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int totalAcc = 0;
char password[20];

struct account
{
    char name[30];
    char password[10];
    int accnum;
    int totalfund;
    struct account *next;
};

void readPassword()
{
    int i = 0;
    char ch;
    while (1) 
    {
        ch = getch();

        if (ch == 13) 
            break;

        if (ch == 8) 
        { 
            if (i > 0) {
                printf("\b \b"); 
                i--;
            }
        }
         else
        {
            password[i] = ch;
            printf("*"); 
            i++;
        }
    }

    password[i] = '\0'; // Null-terminate the password string
    
    return 0;
}

struct account *createLinkedList()
{
    totalAcc++;
    struct account *head = NULL;
    struct account *tail = NULL;

    struct account *newaccount = (struct account *)malloc(sizeof(struct account));

    if (newaccount != NULL)
    {
        printf("Enter your name: ");
        scanf("%s", newaccount->name);

        printf("Set your password: ");
        readPassword();
        strcpy(newaccount->password,password);

        printf("Enter your deposit money: ");
        scanf("%d", &newaccount->totalfund);

        printf("your account number is %d ",totalAcc);

        newaccount->next = NULL;

        if (head == NULL)
        {
            head = newaccount;
            tail = newaccount;
        }
        else
        {
            tail->next = newaccount;
            tail = newaccount;
        }
    }
    else
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return head;
}

void main()
{
    createLinkedList();
}