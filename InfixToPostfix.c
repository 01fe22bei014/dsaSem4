#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>


#define MAX_SIZE 100

char infixExp[MAX_SIZE];

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

Stack operandStack,operatorStack;


void initialize(Stack *s)
{

    s->top = -1;
}

int isEmpty(Stack *s)
{
    if( s->top == -1)
        return -1;
    else
        return 0;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char item)
{
    if (!isFull(s))
        {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
        {
        return s->items[(s->top)--];
    }
    return '\0';
}

char view(Stack *s)
{
    if(isEmpty(s)!=-1)
        return s->items[s->top];
    else
        return '@';
}


bool precedence(char operator1, char operator2)
{
    if(operator1=='*' && operator2=='+')
    {
        return true;
    }

    else if(operator1=='*' && operator2=='-')
    {
        return true;
    }

    else if(operator1=='/' && operator2=='+' )
    {
        return true;
    }
    else if(operator1=='/' && operator2=='-' )
    {
        return true;
    }
    else if(operator1==operator2)
    {
        return true;

    }
    else if(operator1=='+' && operator2=='-')
    {
        return true;
    }
     else if(operator1=='-' && operator2=='+')
    {
        return true;
    }
     else if(operator1=='*' && operator2=='/')
    {
        return true;
    }
     else if(operator1=='/' && operator2=='*')
    {
        return true;
    }
    return false;


}

bool isOperand(char ops)
{
    if(ops=='+' || ops=='-'|| ops=='*' || ops=='/')
    {
        return false;
    }
    return true;
}

void printStack(Stack *s)
{
    if(isEmpty(s)!=-1)
    {
        for(int i=0 ; i<=s->top ; i++)
        {
            printf("%c",s->items[i]);

        }

    }

}

int main()
{
    initialize(&operandStack);
    initialize(&operatorStack);

    printf("enter expression ");
    scanf("%s",infixExp);

    int startIndex=0;
    int length = 0;
    length = strlen(infixExp);

    while(startIndex<length)
    {
         char temp=infixExp[startIndex];
      /*  printf("parsing char is %c",temp);
        printf("\n operand stack :");
        printStack(&operandStack);

        printf("\n operator stack :");
        printStack(&operatorStack);
        printf("\n");
        getch();*/


        if(isOperand(temp)==true)
        {
            push(&operandStack,temp);
        }
        else
            {
                if(isEmpty(&operatorStack)==-1)
                {
                    push(&operatorStack,temp);
                }
                else
                {
                    if(precedence(temp,view(&operatorStack)))
                    {
                        push(&operatorStack,temp);

                    }
                    else
                    {
                        push(&operandStack,pop(&operatorStack));
                        while(isEmpty(&operatorStack)!=-1)
                        {
                            if(precedence(view(&operatorStack),temp))
                            {
                                push(&operandStack,pop(&operatorStack));

                            }

                        }

                        push(&operatorStack,temp);


                    }

                }


            }
 startIndex++;
    }

    while(isEmpty(&operatorStack)!=-1)
    {
        push(&operandStack,pop(&operatorStack));
    }

    printStack(&operandStack);

}


