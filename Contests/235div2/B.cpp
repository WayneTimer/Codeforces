#include <cstdio>
#include <cstring>

int n,m;
int a[4010];

int main()
{
  int i,op,x,y,ma,mi;
  memset(a,0,sizeof(a));
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    scanf("%d%d",&op,&x);
    if (op==1)
    {
      scanf("%d",&y);
      a[x]=2;
      a[y]=1;
    }
    else
      a[x]=2;
  }
  ma=0;
  mi=0;
  for (i=1;i<n;i++)
    if (a[i]==0)
    {
      ma++;
      mi++;
      if (i+1<n && a[i+1]==0)
      {
        ma++;
        i++;
      }
    }
  printf("%d %d\n",mi,ma);
  return 0;
}
