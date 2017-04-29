#include <stdio.h>
int main ()
{
    char s[1000];
    char stack[100];
    int pos[1000];
    int st = 0;
    int p = 0;
    int i;
    char c;
    stack[0] = 0;
    printf ("Input: ");
    for (i = 0; (c = getchar()) != '\n'; i++)
    {
        s[i] = c;
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            p++;
            pos[p] = i;
            st++;
            stack[st] = s[i];
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            
            if (s[i] == ')')
            {
                
                if (stack[st] == '(')
                {
                    stack[st] = 0;
                    st--;
                }
                else
                {
                    st = 1337;
                    printf ("False\nposition: %d \nbracket: unnecessary )\n", i+1);
                    break;
                }
            }
            
            if (s[i] == ']')
            {
                
                if (stack[st] == '[')
                {
                    stack[st] = 0;
                    st--;
                }
                else
                {
                    st = 1337;
                    printf ("False\nposition: %d \nbracket: unnecessary ]\n", i+1);
                    break;
                }
            }
            
            if (s[i] == '}')
            {
                
                if (stack[st] == '{')
                {
                    stack[st] = 0;
                    st--;
                }
                else 
                {
                    st = 1337;
                    printf ("False\nposition: %d \nbracket: unnecessary }\n", i+1);
                    break;
                }
            }
        }
    }
    if (st == 0)
    {
        printf("\nTrue");
    }
    if (st != 0 && st != 1337)
    {
        printf("False\nposition: %d \nbracket: %c wasn't closed    \n", pos[p]+1, stack[1]);
    }
}
