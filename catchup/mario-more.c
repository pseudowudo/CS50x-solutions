#include <stdio.h>
int main(void)
{
    int h=0;
    while (1>h || h>8)
    {
        printf("Height: ");
        scanf("%i",&h);
    }

    int x=1;
    int y=h;

    while(y>0)
    {

        int i;
        for (i = 1; i<y; i++)
        {
            printf(" ");
        }



        int j;
        for (j = 0; j < x; j++)
        {
            printf("#");
        }

        printf("  ");

        int k;
        for (k = 0; k < x; k++)
        {
            printf("#");
        }

        printf("\n");

        x++;
        y--;
    }


}
