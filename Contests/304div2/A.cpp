#include <cstdio>

int main()
{
    int k,n,w,s;
    scanf("%d%d%d",&k,&n,&w);
    s = (1+w)*w/2 * k;
    s = s - n;
    if (s<=0)
        puts("0");
    else
        printf("%d\n",s);
    return 0;
}
