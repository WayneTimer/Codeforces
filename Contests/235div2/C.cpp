#include <cstdio>

int n,m;

int main()
{
  int s;
  scanf("%d%d",&n,&m);
  if (n>m+1) puts("-1");
  else if (n==m+1)
  {
    for (s=1;s<=m;s++)
      printf("01");
    puts("0");
  }
  else
  {
    s=n<<1;
    s+=2;
    if (m>s) puts("-1");
    else
    {
      while (n>0 && m>0 && m>n)
      {
        printf("110");
        m-=2;
        n--;
      }
      for (;n>0 && m>0;n--,m--)
        printf("10");
      while (n>m && n>0) 
      {
        printf("0");
        n--;
      }
      while (m>n && m>0)
      {
        printf("1");
        m--;
      }
      puts("");
    }
  }
  return 0;
}
