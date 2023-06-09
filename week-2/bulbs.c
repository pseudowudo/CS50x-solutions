//giving head
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//ref
void print_bulb(int x);

//main
int main(void)
{
    string x=get_string("Message: ");
    int c=0;
    while (c<strlen(x))
    {
        int y=(int)x[c];
        c++;
        print_bulb(y);
    }
}

//myfunc
void print_bulb(int x)
{
    int y=7;
    int bits[8];
    while (y>-1)
    {
        if (x%2==0)
        {
            bits[y]=0;
            x=x/2;
            y--;
        }
        else
        {
            bits[y]=1;
            x=x/2;
            y--;
        }
    }
    y++;
    while (y<8)
    {
        if (bits[y]!=0)
        {
            printf("\U0001F7E1");
        }
        else
        {
            printf("\U000026AB");
        }
        y++;
    }
    printf("\n");
}
