#include <stdio.h>
#include <math.h>
void printX();
void printFx();
double check(double a, int c);
void printFor(double x1, double x2, double period, int a);
void printWhile(double x1, double x2, double period, int a);
void printDoWhile(double x1, double x2, double period, int a);
void outputValue(double x1, int a);
int main()
{
    double x1=0, x2=0, voidValue, period, iteration=0;
    x1=check(x1, 1);
    x2=check(x2, 1);
    iteration=check(iteration, 2);
    if(x1==x2 || iteration<1)
        printf("System Error, please correct data");
    else
    {
        if(x1>x2)
        {
            voidValue=x2;
            x2=x1;
            x1=voidValue;
        }
        period=(x2-x1)/(iteration-1);
        printf("Your interval is from %g to %g and %g iteration\n", x1, x2, iteration );
        printf("Your function is f(x)=tg(x)*sqrt(x)");
        printf("\n\nfor:\n");
        printX();
        printFor(x1, x2, period, 2);
        printFx();
        printFor(x1, x2, period, 1);
        printf("\n\nwhile:\n");
        printX();
        printWhile(x1, x2, period, 2);
        printFx();
        printWhile(x1, x2, period, 1);
        printf("\n\ndo while:\n");
        printX();
        printDoWhile(x1, x2, period, 2);
        printFx();
        printDoWhile(x1, x2, period, 1);
    }
    return 0;
}
double check(double a, int c)
{
    double b;
    do
    {
        if(c==1)
            printf("Enter the interval: ");
        if(c==2)
            printf("Enter the itaration: ");
        fflush(stdin);
        b = scanf("%lf", &a);
    }
    while (b < 1);
    return a;
}
void printX()
{
     printf("x    |");
}
void printFx()
{
    printf("\nf(x) |");
}
void printFor(double x1, double x2, double period, int a)
{
    for(double i=x1; i<=x2; i+=period)
    {
        outputValue(i,a);
    }
}
void printWhile(double x1, double x2, double period, int a)
{
    while(x1<=x2)
    {
        outputValue(x1, a);
        x1+=period;
    }
}
void printDoWhile(double x1, double x2, double period, int a)
{
    do
    {
        outputValue(x1, a);
        x1+=period;
    }
    while(x1<=x2);
}
void outputValue(double x1, int a)
{
    double output;
    if(a==1)
        output=tan(x1)*sqrt(x1);
    if(a==2)
        output=x1;
    if(output>=0)
        printf(" %-6.4g|", output);
    else
        printf("%-7.4g|", output);
}
