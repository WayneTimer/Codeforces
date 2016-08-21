#include <cstdio>
#include <cstring>

int n,m;
char a[201];

int main()
{
    bool res;
    res = true;
    scanf("%d %d",&n,&m);
    gets(a);
    for (int i=0;i<n;i++)
    {
        gets(a);
        int l = strlen(a);
        for (int j=0;j<l;j++)
        {
            if (a[j]=='C' ||
                a[j]=='M' ||
                a[j]=='Y')
                res=false;
        }
    }
    if (res)
        puts("#Black&White");
    else
        puts("#Color");
    return 0;
}
