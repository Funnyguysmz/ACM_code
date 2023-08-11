#include<iostream>
#include<queue>
#include<cstring>
#define endl "\n"
typedef long long ll;
const int maxn=1e5+5,maxm=2e5+5,INF=0x3f3f3f3f;
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

void add(int u,int v,int w)
{
    addedge(u,v,w);
    addedge(v,u,0);
}

int n,m,s,t;  //n个点，m条边，s是源点，t是汇点
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
        for(int i=0;i<=n;++i) work[i]=head[i];
        while(tinc=dfs(s,1e18)) ret+=tinc;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        std::memset(head,-1,sizeof head);
        s=1,t=n;
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        printf("%lld\n",Dinic());
    }
    return 0;
}