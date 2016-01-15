#include <cstdio>

long long a,b,x;
long long s,cnt;

int main()
{
    long long c;
    scanf("%I64d%I64d",&a,&b);
    c=b;
    x=1;
    s=1;
    c>>=1;
    while (c)
    {
        x<<=1;
        s|=x;
        c>>=1;
    }
    cnt=0;
    while (x>1)
    {
      x>>=1;
      //printf("%lld s^x = %lld\n",s,s^x);
      //printf("%llo s^x = %llo\n",s,s^x);
      if (s<a) break;
      long long k;
      k = x;
      while (k)
      {
          long long t;
          t = s^k;
          //printf("%lld\n",t);
          if (t>=a && t<=b) cnt++;
          k>>=1;
      }
      s>>=1;
    }
    printf("%I64d\n",cnt);
    return 0;
}
