//this is mario-less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int eh=1;
    int a=0;
    int x=0;
    while (x<1 || x>8)
    {
        x = get_int("Height: ");
        if (0<x && x<9)
        {
            for (int y=x; y>0;y--)
            {
                a++;
                int c=x-a;
                for (int d=c; d>0;d--)
                {
                    printf(" ");
                }
                for (int b=a; b>0;b--)
                {
                    printf("#");
                }
                printf("\n");
            }
        }
    }
}
