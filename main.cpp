#include <bits/stdc++.h>
using namespace std;
class NetFlow
{
  public:
    int maxn;
    NetFlow(int n_num,int m_num,const int max):maxn(max),cnt(0),n(n_num),m(m_num){
        edge = new node[maxn*2];
        deep = new int[maxn];
        head = new int[maxn];
        fill(head,-1,maxn); 
    };
    ~NetFlow(){
        delete edge;
        delete deep;
        delete head;
    }
  private:
    const int INF = 0xfffffff;
    int n, m,cnt;
    int *deep,*head; 
    struct node
    {
        int to;
        int next;
        int weight;
    }*edge;
    void fill(int *a,int num,int len){
        for(int i = 0;i < len;i++)
            a[i] = num;
    }
    int bfs(int S, int T)
    {
        queue<int> Q;
        fill(deep, 0, maxn);
        Q.push(S);
        deep[S] = 1;
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if (now == T)
                return 1;
            for (int i = head[now]; ~i; i = edge[i].next)
            {
                int next = edge[i].to;
                if (edge[i].weight && !deep[next])
                {
                    deep[next] = deep[now] + 1;
                    Q.push(next);
                }
            }
        }
        return deep[T];
    }
    int dfs(int now, int flow, int aim)
    {
        if (now == aim)
            return flow;
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int next = edge[i].to;
            if (deep[next] == deep[now] + 1 && edge[i].weight)
            {
                int fl = dfs(next, min(edge[i].weight, flow), aim);
                if (fl > 0)
                {
                    edge[i].weight -= fl;
                    edge[i ^ 1].weight += fl;
                    return fl;
                }
            }
        }
        return 0;
    }
  public:
    void add_edge(int u, int v, int w)
    {
        edge[cnt].next = head[u];
        edge[cnt].to = v;
        edge[cnt].weight = w;
        head[u] = cnt++;
    }
    int dinic(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t)){
            ans += dfs(s, INF, t);}
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int T, u, v, w,n,m;
    cin >> T;
    for(int t_case = 1;t_case <= T;t_case++)
    {
        cin >> n >> m;
        NetFlow *solve = new NetFlow(n,m,1006);
        for (int index = 0; index < m; index++){
            cin >> u >> v >> w;
            solve->add_edge(u, v, w);
            solve->add_edge(v, u, 0);           
        }
        printf("Case %d: %d\n",t_case,solve->dinic(1,n));
        delete solve;
    }
    return 0;
}
