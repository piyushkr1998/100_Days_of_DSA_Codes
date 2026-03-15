#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    int x;
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);

    return x;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int op1, op2;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');   
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    return pop();
}

int main()
{
    char postfix[100];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}