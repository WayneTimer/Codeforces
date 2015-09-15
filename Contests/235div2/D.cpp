/*
设f[i][j]表示 在选取各数位状态为j，组成的数除以m余数为j的数的个数。
则f[i][j]=sigma(f[i屏蔽第k位][(x+a[k])%m==j])
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll s;
ll f[1<<18][100];
int m,n;
int a[18];

int main()
{
  ll i;
  int j,k,last,t;
  scanf("%I64d%d",&s,&m);
  n=0;
  while (s)
  {
    a[n++]=s%10;
    s/=10;
  }
  sort(a,a+n);
  memset(f,0,sizeof(f));
  f[0][0]=1;
  for (i=0;i<1<<n;i++)
    for (j=0;j<m;j++)
      if (f[i][j])
      {
        last=-1;
        for (k=n-1;k>=0;k--)
          if (!(i & 1<<k) && last!=a[k])
          {
            if (i==0 && a[k]==0) break;
            //反向遍历数组a,使得判前导0时这里可直接break
            t=(j*10+a[k])%m;
            f[i | 1<<k][t]+=f[i][j];
            last=a[k];
          }
      }
  printf("%I64d\n",f[(1<<n)-1][0]);
  return 0;
}
