//header files
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//myfunctionreference
int get_grd(string txt);
//main
int main(void)
{
    //input
    string txt=get_string("Text: ");
    // myfunctionusage
    int grade=get_grd(txt);
    //output
    if (grade<1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade>=16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
//myfunction
int get_grd(string txt)
{
    int len=strlen(txt);
    int letters=0;
    int counter=0;
    int words=1;
    int sentences=0;
    while (counter<(len+2))
    {
        if (txt[counter]=='.'||txt[counter]=='!'||txt[counter]=='?')
        {
            sentences++;
            counter++;
        }
        else if (txt[counter]==' ')
        {
            words++;
            counter++;
        }
        else
        {
            char x=(txt[counter]);
            if (isalpha(x)==0)
            {
                counter++;
            }
            else
            {
                letters++;
                counter++;
            }
        }
    }
    //lettersper100words
    float l= ((letters*100)/(float)words);
    //sentencesper100words
    float s= ((sentences*100)/(float)words);

    int index = round(0.0588*l-0.296*s-15.8);
    return index;
}
