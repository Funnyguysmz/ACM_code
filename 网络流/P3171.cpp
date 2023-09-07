#include<bits/stdc++.h>
#define endl "\n"
const int maxm=5e5+5,INF=0x3f3f3f3f,maxn=5000+5;
typedef long long ll;
int head[maxn]; //头节点，这里初始化为-1表示该顶点还没有边
int to[maxm];   //该边所指向的点的编号
ll cap[maxm];  //该边的容量
int nt[maxm];   //下一条边
int cnt;

void addedge(int u,int v,ll w)
{
    to[cnt]=v;
    cap[cnt]=w;
    nt[cnt]=head[u];
    head[u]=cnt++;
}
void add(int u,int v,ll w)
{
    addedge(u,v,w);
    addedge(v,u,0);
}

ll n,m,s,t;  //n个点，m条边，s是源点，t是汇点
int ly[maxn],work[maxn];

bool bfs()
{
    std::queue<int> q;
    std::memset(ly,-1,sizeof ly);
    q.push(s);
    ly[s]=0;  //分层，源点层为0
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=nt[i])
        {
            if(ly[to[i]]>=0||!cap[i]) continue;
            ly[to[i]]=ly[now]+1;
            if(to[i]==t) return true;
            q.push(to[i]);
        }
    }
    return false;
}

ll dfs(int cur,ll inc)
{
    ll tinc;
    if(cur==t) return inc;
    for(int &i=work[cur];~i;i=nt[i])
    {
        if(cap[i]&&ly[to[i]]==ly[cur]+1&&(tinc=dfs(to[i],std::min(inc,cap[i]))))
        {
            cap[i]-=tinc;
            cap[i^1]+=tinc;
            return tinc;
        }
    }
    return 0;
}

ll Dinic()
{
    ll ret=0,tinc;
    while(bfs())
    {
        std::memcpy(work,head,sizeof head);
        while((tinc=dfs(s,1e18))) ret+=tinc;
    }
    return ret;
}

ll dist[maxn];
bool vis[maxn];
std::vector<std::pair<int,ll> > G[maxn];
struct ss{
    int to;
    ll w;
    ss(int a,ll b)
    {
        to=a,w=b;
    }
    bool operator<(const ss &i)const{
        return w>i.w;
    }
};

void spfa()
{
    for(int i=2;i<=n;++i) dist[i]=1e18;
    std::queue<ss> q;
    ss t(1,0ll);
    q.push(t);
    vis[1]=true;
    while(!q.empty())
    {
        ss x=q.front();
        q.pop();
        for(auto &p:G[x.to])
        {
            if(dist[p.first]>dist[x.to]+p.second)
            {
                dist[p.first]=dist[x.to]+p.second;
                if(!vis[p.first])
                {
                    vis[p.first]=true;
                    ss te(p.first,dist[p.first]);
                    q.push(te);
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::memset(head,-1,sizeof head);
    std::cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        ll w;
        std::cin>>u>>v>>w;
        G[u].push_back(std::make_pair(v,w));
        G[v].push_back(std::make_pair(u,w));
    }
    spfa();
    s=0,t=(n<<1)+1;
    add(s,1,1e18),add(n<<1,t,1e18);
    for(int i=1;i<=n;++i)
    {
        ll c;
        std::cin>>c;
        if(i!=1&&i!=n)
        {
            add(i,i+n,c);
        }
        else
        {
            add(i,i+n,1e18);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(auto &j:G[i])
        {
            if(dist[j.first]==dist[i]+j.second)
            {
                add(i+n,j.first,1e18);
            }
        }
    }
    std::cout<<Dinic()<<endl;
}
