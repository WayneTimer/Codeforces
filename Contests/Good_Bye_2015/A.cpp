#include <cstdio>

char s[100];
int n;


int main()
{
    scanf("%d of %s",&n,s);
    if (s[0]=='w')
    {
        if (n>=1 && n<=4) puts("52");
        else if (n>=5 && n<=6) puts("53");
        else if (n==7) puts("52");
    }
    else
    {
        if (n<=29) puts("12");
        else if (n==30) puts("11");
        else if (n==31) puts("7");
    }
    return 0;
}
