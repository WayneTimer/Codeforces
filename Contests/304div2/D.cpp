// Number theory: prime number
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 5000000

bool p[5000010];
long long a[5000010];
vector<int> prime;
int plen;

void make_prime_list()
{
    memset(p,true,sizeof(p));
    for (int i=2;i<=2500000;i++)
    {
        if (!p[i]) continue;
        for (int j=2;i*j<=MAXN;j++)
            p[i*j]=false;
    }
    prime.clear();
    for (int i=2;i<=MAXN;i++)
        if (p[i]) prime.push_back(i);
    plen=prime.size();
}

void work(long long x,int u,int s)
{
    a[x]=s;
    for (int i=u;i<plen;i++)
        if (x*prime[i]<=MAXN) work(x*prime[i],i,s+1);
        else break;
}

int main()
{
    make_prime_list();
    memset(a,0,sizeof(a));
    work(1,0,0);
    for (int i=2;i<=MAXN;i++)
    {
        a[i]+=a[i-1];
    }
    int t,x1,x2;
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d%d",&x1,&x2);
        printf("%I64d\n",a[x1]-a[x2]);
    }
    return 0;
}
