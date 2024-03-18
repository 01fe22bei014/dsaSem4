#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 100

struct stack
{
    char bracket[SIZE];
    int top;
};

void initStack(struct stack *s)
{
    s->top=-1;
}

int isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return -1;
    }
    else
        return 0;

}

int isFull(struct stack *s)
{
    if(s->top==SIZE-1)
    {
        return -1;

    }
    else
        return 0;



}



void push(struct stack *s,char bracket)
{
    if(isFull(s)==-1)
    {
        printf("stack overflow ");
    }
    else
    {
        s->top++;
        s->bracket[s->top]=bracket;

    }

}


char pop(struct stack *s)
{
    int temp;
    if(isEmpty(s)==-1)
    {
        printf("underflow");

    }
    else
    {
        temp=s->bracket[s->top];
        s->top--;
    }
    return temp;

}

void takeInput(struct stack *s)
{
    int bracket;
    printf("enter your bracket ");
    scanf("%c",&bracket);
    push(s,bracket);
}

bool CheckParenthesis(struct stack *s)
{
    if(s->top==-1 || s->top==0)
    {
        takeInput(s);
    }
    else
    {
        if(s->bracket[s->top]==s->bracket[s->top-1])
        {
            pop(s);
        }
        else
        {
            takeInput(s);
        }
    }

}

int main()
{
    struct stack *mainStack;
    initStack(mainStack);
    CheckParenthesis(mainStack);
}