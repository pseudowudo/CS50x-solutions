#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string x = get_string("who're you, eh? ");
    printf("hello, %s\n", x);
}