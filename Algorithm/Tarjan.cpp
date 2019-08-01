#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define maxn 200007
const int INF=0x3f3f3f3f;


int DFN[maxn],low[maxn],num,index;
bool inStack[maxn];
vector <int> G[maxn];
stack <int> S;
int in[maxn],belong[maxn];
void Tarjan(int u)
{
    int v;
    DFN[u]=low[u]=index++;
    inStack[u]=true;
    S.push(u);
    for(int i=0;i<G[u].size();i++)
    {
        v=G[u][i];
        if(!DFN[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v])
        {
            low[u]=min(low[u],DFN[v]);
        }
    }
    if(DFN[u]==low[u])
    {
        num++;
        do
        {
            v=S.top();
            S.pop();
            belong[v]=num;
        }while(v!=u);
    }
}

void SCC(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!DFN[i])
        {
            Tarjan(i);
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int a,b;
        memset(DFN,0,sizeof(DFN));
        memset(low,0,sizeof(low));
        index=num=0;
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
        }
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
        }
        SCC(n);
        if(num==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
