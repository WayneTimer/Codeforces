#include <cstdio>
#include <cstring>

#define MOD 1000000007
#define MAXN 5010

int f[MAXN][MAXN];
int n;
char str[MAXN];
int s[MAXN][MAXN];
// s[i][j]: From str[i],str[j], the first one str[i]!=str[j] shift position
// that is compare(str[i,i+k],str[j,j+k]), only need to compare(str[i+f[i][j]],str[j+f[i][j]])

inline int cmp(int x1,int y1,int x2,int y2)
{
    if (y2>=n) return 0;
    int l;
    l = s[x1][x2];
    if (l>y1-x1) return 0;
    return (str[x1+l]<str[x2+l]);
}

int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for (int i=n-1;i>=0;i--)
        for (int j=n-1;j>=0;j--)
            if (str[i]==str[j]) s[i][j] = s[i+1][j+1] + 1;

    for (int j=n-1;j>=0;j--)
        for (int i=j;i>=0;i--)
        {
            int x,y;
            bool flag;
            flag = true;
            x = j+1;
            y = j+j-i+1;
            if (str[i]!='0')
            {
                if (j==n-1)
                    f[i][j] = 1;
                else
                    if (cmp(i,j,x,y))
                    {
                        f[i][j]+=f[x][y];
                        f[i][j]%=MOD;
                        flag = false;
                    }
            }
            if (j+1<n)
            {
                f[i][j]+=f[i][j+1];
                f[i][j]%=MOD;
            }
            if (str[i]!='0' && flag && y+1<n)
            {
                f[i][j]+=f[x][y+1];
                f[i][j]%=MOD;
            }
        }
    printf("%d\n",f[0][0]);
    return 0;
}
