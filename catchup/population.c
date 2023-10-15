#include <stdio.h>
int main(void)
{
    int ss=0;
    int es=0;
    int pop;
    int y=0;
    while (ss<9)
    {
        printf("start size: ");
        scanf("%i",&ss);
    }
    while (es<ss)
    {
        printf("end size: ");
        scanf("%i",&es);
    }
    pop=ss;
    while(pop<es)
    {
        y++;
        pop=pop+(pop/3)-(pop/4);
    }
    printf("%d\n",y);
    
}
