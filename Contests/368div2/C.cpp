// Only consider input as a short side
// cause a+b>c, a.max = 10^9,  c <= 2*10^9 < output.max (10^18)
/*
a^2 + b^2 = c^2
a^2 = (c+b)(c-b)

Solution:
0. a=1, a=2, can not be as a short side

Consider a>=3 (a^2>=9):
1. a is odd, a^2 is also odd,
   then construct (c-b)==1, since a^2 is odd, we have a^2 = 2*p+1 = p + p+1, (a^2>=9, p>=4)
   then we can always have c=p+1, b=p.
   Thus, b = (a^2-1)/2, c=b+1
2. a is not odd, a^2 is also not odd,
   then construct (c-b)==2, since a^2 is not odd, we have a^2 = 2*p, then c+b=p, (a^2>=16, p>=8).
   Since a is not odd, a at least has one prime factor 2: a = 2 * ...,
   so, a^2 = 2^2 * ..., thus, 2*p = 2^2 * ..., p = 2 * ..., so p is also not odd,
   thus p/2 is an integer, construct c=p/2+1, b=p/2-1 (since p>=8, p/2-1>=3, b is always exist).
   Thus, b = (a^2)/(2^2)-1, c=b+2
*/
#include <cstdio>

typedef long long ll;

int main()
{
    ll n,b;
    scanf("%I64d",&n);
    if (n<=2)
        puts("-1");
    else if (n&1)
    {
        b = (n*n-1)>>1;
        printf("%I64d %I64d\n",b,b+1);
    }
    else
    {
        b=((n*n)>>2)-1;
        printf("%I64d %I64d\n",b,b+2);
    }
    return 0;
}
