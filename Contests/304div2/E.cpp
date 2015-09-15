#include <cstdio>
#include <vector>

using namespace std;

template <typename T>
class Edge
{
public:
    int x,y; // from x to y
    T v; // v is value/size

    Edge(int _x,int _y,T _v)
    {
        x=_x;
        y=_y;
        v=_v;
    }
};

template <typename T>
class Graph
{
public:
    int n; // n nodes
    vector< Edge<T> > e; // edges

    Graph()
    {
        n=0;
        e.clear();
    }
};

/*
   Initial graph has n nodes numbered from 0 ~ n-1,
   to calculate the max-flow from start node 0 to end node n-1,
   we make every node number increase by 1,
   then 1 is the start node, n is the end node,
   and calculate the max-flow from 1 to n.
*/
template <typename T>
class Maxflow
{
private:
    T MAXT;
    vector< vector<T> > limit; // size = n+1
    vector< vector<T> > flow;
    int n,m,vec_size; // n is origin node size, vec_size = n+1

public:
    Maxflow(Graph<T> graph,T _MAXT)
    {
        MAXT = _MAXT;
        n = graph.n;
        m = graph.e.size();
        vec_size = n+1;
        limit = vector< vector<T> >(vec_size,vector<T>(vec_size));
        flow = vector< vector<T> >(vec_size,vector<T>(vec_size));
        for (int i=0;i<m;i++)
        {
            limit[graph.e[i].x+1][graph.e[i].y+1] += graph.e[i].v; // += handle multiple paths between x,y
        }
    }

    // BFS find an augmenting path, then slack
    T solve()
    {
        vector<int> last;
        vector<bool> check;

        do
        {
            last = vector<int>(vec_size);
            check = vector<bool>(vec_size);
            last[1] = vec_size;

            do
            {
                int i;
                i=0;
                do
                {
                    i++;
                    if (i>n || (last[i]!=0 && !check[i])) break;
                } while (true);
                if (i>n) break;
                for (int j=1;j<=n;j++)
                    if (last[j]==0)
                        if (flow[i][j] < limit[i][j])
                            last[j] = i;
                        else if (flow[j][i] > 0)
                            last[j] = -i;
                check[i]=true;
            } while (last[n]==0); // find augmenting path
            if (last[n]==0) break;

            T x,delta;
            delta = MAXT;
            int i,j;
            i=n;
            do
            {
                j=i;
                if (last[j]<0)
                    i = -last[j];
                else
                    i = last[j];
                if (last[j]>0)
                    x = limit[i][j] - flow[i][j];
                else
                    x = flow[j][i];
                if (x<delta) delta=x;
            } while (i!=1);

            i=n;
            do
            {
                j=i;
                if (last[j]<0)
                    i = -last[j];
                else
                    i = last[j];
                if (last[j]>0)
                    flow[i][j] += delta;
                else
                    flow[j][i] -= delta;
            } while (i!=1);
        } while (true);

        T s = T();
        for (int j=2;j<=n;j++)
            if (flow[1][j]>0) s+=flow[1][j];
        return s;
    }

    void output_flow(); // need to be define when use
};

//----------------

Graph<int> gra;
int sum;

template <typename T>
void Maxflow<T>::output_flow()
{
    int l;
    l = (n-1)>>1;
    for (int i=2;i<2+l;i++)
    {
        for (int j=2+l;j<2+(l<<1);j++)
            if (flow[i][j]>0) printf("%d ",flow[i][j]);
            else printf("0 ");
        puts("");
    }
}

inline bool build()
{
    int s1,s2,n,m,nn,x;

    s1=s2=0;

    scanf("%d%d",&n,&m);
    nn=n;
    for (int j=1;j<=n;j++)
    {
        scanf("%d",&x);
        s1+=x;
        gra.e.push_back(Edge<int>(0,j,x));
        gra.e.push_back(Edge<int>(j,j+n,999999));
    }
    n=(n<<1)+1;
    for (int i=nn+1;i<n;i++)
    {
        scanf("%d",&x);
        s2+=x;
        gra.e.push_back(Edge<int>(i,n,x));
    }
    n++;
    gra.n=n;

    if (s1!=s2) return false;
    sum=s1;

    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        gra.e.push_back(Edge<int>(x,y+nn,999999));
        gra.e.push_back(Edge<int>(y,x+nn,999999));
    }
    return true;
}

int main()
{
    build();
    Maxflow<int> maxflow(gra,999999);
    int s;
    s=maxflow.solve();
    if (sum==s)
    {
        puts("YES");
        maxflow.output_flow();
    }
    else
        puts("NO");
    return 0;
}
