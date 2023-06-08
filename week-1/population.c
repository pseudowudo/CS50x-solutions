#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int x=0;
    int y=0;
    while (x<9)
    {
        x=get_int("Start size: ");
    }
    // TODO: Prompt for end size
    while (y<x)
    {
        y=get_int("End size: ");
    }
    // TODO: Calculate number of years until we reach threshold
    int t=0;
    while (x<y)
    {
        t++;
        x=x+(x/3)-(x/4);
    }
    // TODO: Print number of years
    printf("Years: %d\n",t);
}
