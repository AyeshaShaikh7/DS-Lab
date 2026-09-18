#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    int arr[100];
    int top;
};

void push(struct Stack *stack, int value)
{
    if (stack->top == 99)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int evaluate(char exp[])
{
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(exp); i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            int num = ch - '0';
            push(&stack, num);
        }
        else
        {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (ch)
            {
            case '+':
                push(&stack, a + b);
                break;

            case '-':
                push(&stack, a - b);
                break;

            case '*':
                push(&stack, a * b);
                break;

            case '/':
                push(&stack, a / b);
                break;
            }
        }
    }

    return pop(&stack);
}

int main()
{
    char exp[] = "82/53*+41-/";
    printf("%d\n", evaluate(exp));
    return 0;
}