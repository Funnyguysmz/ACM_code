#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=1e4+5,maxm=2e4+5,INF=0x3f3f3f3f;
const ll INFF=0x3f3f3f3f3f3f3f3f;
int head[maxn]; //头节点，这里初始化为-1表示该顶点还没有边
int to[maxm];   //该边所指向的点的编号
ll cap[maxm];  //该边的容量
ll cost[maxm];  //该边的费用
int nt[maxm];   //下一条边
int cnt;

void addedge(int u,int v,ll w,ll c)
{
    cost[cnt]=c;
    to[cnt]=v;
    cap[cnt]=w;
    nt[cnt]=head[u];
    head[u]=cnt++;
}

void add(int u,int v,ll w,ll c)
{
    addedge(u,v,w,c);
    addedge(v,u,0,-c);
}

int n,m,s,t;
ll maxflow,mincost;
ll dis[maxn],incf[maxm],pre[maxm];
bool vis[maxn];

bool spfa()
{
    std::queue<int> q;
    std::memset(dis,0x3f,sizeof dis);
    std::memset(vis,false,sizeof vis);
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    incf[s]=1<<30;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=nt[i])
        {
            if(!cap[i]) continue;
            int v=to[i];
            if(dis[v]>dis[u]+cost[i])
            {
                dis[v]=dis[u]+cost[i];
                incf[v]=std::min(incf[u],cap[i]);
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(dis[t]==INFF) return false;
    return true;
}

void MCMF()
{
    while(spfa())
    {
        int x=t;
        maxflow+=incf[t];
        mincost+=dis[t]*incf[t];
        int i;
        while(x!=s)
        {
            i=pre[x];
            cap[i]-=incf[t];
            cap[i^1]+=incf[t];
            x=to[i^1];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>m>>s>>t;
    std::memset(head,-1,sizeof head);
    for(int i=1;i<=m;++i)
    {
        int u,v;
        ll w,c;
        std::cin>>u>>v>>w>>c;
        add(u,v,w,c);
    }
    MCMF();
    std::cout<<maxflow<<' '<<mincost<<endl;
    return 0;
}