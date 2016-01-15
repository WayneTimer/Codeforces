#include <cstdio>
#include <cstring>

int h,w;
bool a[510][510];
int f[510][510];
char str[510];
int row[510][510];
int col[510][510];

inline void init()
{
    memset(row,0,sizeof(row));
    for (int i=1;i<h;i++)
        for (int j=1;j<=w;j++)
        {
            row[i][j] = row[i][j-1];
            if (a[i][j] && a[i+1][j]) row[i][j]++;
        }
    memset(col,0,sizeof(col));
    for (int j=1;j<w;j++)
        for (int i=1;i<=h;i++)
        {
            col[i][j] = col[i-1][j];
            if (a[i][j] && a[i][j+1]) col[i][j]++;
        }

    memset(f,0,sizeof(f));
    for (int j=2;j<=w;j++)
    {
        f[1][j] = f[1][j-1];
        if (a[1][j] && a[1][j-1]) f[1][j]++;
    }
    for (int i=2;i<=h;i++)
    {
        f[i][1] = f[i-1][1];
        if (a[i][1] && a[i-1][1]) f[i][1]++;
        for (int j=2;j<=w;j++)
        {
            f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1];
            if (a[i][j] && a[i-1][j]) f[i][j]++;
            if (a[i][j] && a[i][j-1]) f[i][j]++;
        }
    }
}

int main()
{
    scanf("%d%d",&h,&w);
    memset(a,false,sizeof(a));
    for (int i=0;i<h;i++)
    {
        scanf("%s",str);
        for (int j=0;j<w;j++)
            if (str[j]=='.') a[i+1][j+1]=true;
    }
    init();
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
        int x1,y1,x2,y2,s;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        s = f[x2][y2] - f[x2][y1-1] - f[x1-1][y2] + f[x1-1][y1-1];
        s -= (row[x1-1][y2] - row[x1-1][y1-1]);
        s -= (col[x2][y1-1] - col[x1-1][y1-1]);
        printf("%d\n",s);
    }
    return 0;
}
