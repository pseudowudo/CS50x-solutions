#include <stdio.h>
#include <stdlib.h>

long get_card();
int get_digs(long n);
int get_f2(long n);
void digchk(int d);
void lc(long n);
void bc(int d, int f1, int f2);

int main(void)
{
    long n=get_card();
    int d=get_digs(n);
    int f2=get_f2(n);
    int f1=(f2/10);
    digchk(d);
    lc(n);
    bc(d,f1,f2);

}

//myfunctions

long get_card()
{
    long x;
    printf("Number: ");
    scanf("%li",&x);
    return x;
}

int get_digs(long n)
{
    int dig=0;
    long x=n;
    while (x>0)
    {
        x=x/10;
        dig++;
    }
    return dig;
}

int get_f2(long n)
{
    long x=n;
    while ((x/100)>0)
    {
        x=x/10;
    }
    int f2=x;
    return f2;
}

void digchk(int d)
{
    if (d==13||d==15||d==16){}
    else
    {
        printf("INVALID\n");
        exit(0);
    }
}

void lc(long n)
{
    int ss=0;
    int ds=0;
    int tot;
    long x=n;
    int i=0;
    while (x!=0)
    {
        if (i==0)
        {
            i++;
            ss+=(x%10);
            x=(x/10);
        }
        else
        {
            i--;
            int temp=(2*(x%10));
            if (temp>9)
            {
                ds+=temp%10;
                temp=(temp/10);
                ds+=temp;
            }
            else
            {
                ds+=temp;
            }
            x=(x/10);
        }
    }
    tot=ss+ds;
    if ((tot%10)!=0)
    {
        printf("INVALID\n");
        exit(0);
    }
}

void bc(int d, int f1, int f2)
{
    if (d==13)
    {
        if (f1==4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else if (d==15)
    {
        if((f2==34)||(f2==37))
        {
            printf("AMEX\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else if (d==16)
    {
        if (f1==4)
        {
            printf("VISA\n");
        }

        else if((f2>50)&&(f2<56))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

}
