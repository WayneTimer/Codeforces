#include <cstdio>
#include <string>
#include <map>

using namespace std;

typedef pair<string,string> mypair;
map<mypair,int> hash;

mypair calc(string s1,string s2)
{
    mypair res(s1,s2);
    return res;
}

char top(string &x)
{
    int l;
    char res;
    l = x.length();
    res=x[0];
    x=x.substr(1,l-1);
    return res;
}

int main()
{
    int n,k1,k2,x,res;
    string s1,s2;
    mypair s;
    s1="";
    s2="";
    scanf("%d",&n);
    scanf("%d",&k1);
    for (int i=0;i<k1;i++)
    {
        scanf("%d",&x);
        x--;
        char xx;
        xx='0'+x;
        s1=s1+xx;
    }
    scanf("%d",&k2);
    for (int i=0;i<k2;i++)
    {
        scanf("%d",&x);
        x--;
        char xx;
        xx='0'+x;
        s2=s2+xx;
    }

    hash.clear();
    s=calc(s1,s2);
    res=0;
    do
    {
        hash[s]=1;
        res++;
        char x1,x2;
        x1=top(s1);
        x2=top(s2);
        if (x1>x2)
            s1=s1+x2+x1;
        else
            s2=s2+x1+x2;
        if (s1.length()==0 || s2.length()==0) break;
        s=calc(s1,s2);
    } while (hash[s]==0);

    if (s1.length()==0) printf("%d 2\n",res);
    else if (s2.length()==0) printf("%d 1\n",res);
    else puts("-1");
    return 0;
}
