#include <stdio.h>
#include <string.h>
int is_balanced(char input[])
{
    char stack[1000];
    int top = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == '(' || input[i] == '[')
        {
            stack[top] = input[i];
            top++;
        }
        else if(input[i] == ')' || input[i] == ']')
        {
            char temp;
            if(input[i] == ')')temp = '(';
            else temp = '[';
            if(top == 0)return 0;
            top--;
            if(stack[top] != temp)return 0;
        }
    }
    if(top == 0)return 1;
    else return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        char input[1000];
        gets(input);
        if(is_balanced(input))
        {
            printf("Yes\n",input);
        }
        else
        {
            printf("No\n",input);
        }
    }
    return 0;
}

