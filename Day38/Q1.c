
#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];


int front = -1;
int rear = -1;

int empty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}
int size()
{
    if(empty())
        return 0;
    else
        return (rear - front + 1);
}

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = MAX/2;
        deque[front] = x;
    }
    else
    {
      
        front = front - 1;
        deque[front] = x;
    }
}


void push_back(int x)
{
  
    if(front == -1)
    {
        front = rear = MAX/2;
        deque[rear] = x;
    }
    else
    {
        
        rear = rear + 1;
        deque[rear] = x;
    }
}

void pop_front()
{
  
    if(empty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
      
        front = front + 1;
    }
}


void pop_back()
{
    
    if(empty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
     
        rear = rear - 1;
    }
}

void get_front()
{
    if(empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void get_back()
{
    if(empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

int main()
{
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"push_front") == 0)
        {
            scanf("%d",&x);
            push_front(x);
        }

        else if(strcmp(op,"push_back") == 0)
        {
            scanf("%d",&x);
            push_back(x);
        }

        else if(strcmp(op,"pop_front") == 0)
        {
            pop_front();
        }

        else if(strcmp(op,"pop_back") == 0)
        {
            pop_back();
        }

        else if(strcmp(op,"front") == 0)
        {
            get_front();
        }

        else if(strcmp(op,"back") == 0)
        {
            get_back();
        }

        else if(strcmp(op,"empty") == 0)
        {
            printf("%d\n", empty());
        }

        else if(strcmp(op,"size") == 0)
        {
            printf("%d\n", size());
        }
    }

    return 0;
}