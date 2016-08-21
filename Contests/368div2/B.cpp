#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 100010

struct cyr
{
    int y,v;
};

int n,m,k;
vector<cyr> a[MAXN];
int b[MAXN];
vector<int> mark;

int main()
{
    int res = -1;

    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++) a[i].clear();

    for (int i=0;i<m;i++)
    {
        int x,y,v;
        scanf("%d %d %d",&x,&y,&v);
        cyr tmp;
        tmp.y = y;
        tmp.v = v;
        a[x].push_back(tmp);
        tmp.y = x;
        a[y].push_back(tmp);
    }

    memset(b,0,sizeof(b)); // 1 - is center
    mark.clear();
    for (int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        b[x] = 1;
        mark.push_back(x);
    }
    int l = mark.size();
    for (int i=0;i<l;i++)
    {
        int s = a[mark[i]].size();
        for (int j=0;j<s;j++)
            if (b[a[mark[i]][j].y]==0)
                if (res==-1 || a[mark[i]][j].v<res)
                    res = a[mark[i]][j].v;
    }

    printf("%d\n",res);
    return 0;
}
