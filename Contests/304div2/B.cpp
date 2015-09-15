#include <cstdio>
#include <cstring>

int main()
{
    int n,x,s;
    int a[30010];
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
    s=0;
    for (int i=1;n>0;i++)
    {
        if (a[i]==0) continue;
        if (a[i]>1)
        {
            a[i+1] += a[i]-1;
            s += a[i]-1;
        }
        n--;
    }
    printf("%d\n",s);
    return 0;
}
