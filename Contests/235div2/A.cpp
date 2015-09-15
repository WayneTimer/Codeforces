#include <cstdio>

int n,m;
int a[1010];

int main()
{
  int i,s;
  scanf("%d%d",&n,&m);
  s=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    s+=a[i];
  }
  if (s==0) puts("0");
  else if (s<=m && s>=-m)
    puts("1");
  else 
  {
    if (s<0) s=-s;
    i=s/m;
    if (s%m) i++;
    printf("%d\n",i);
  }
  return 0;
}
