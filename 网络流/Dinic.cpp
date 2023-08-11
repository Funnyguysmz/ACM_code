#include<iostream>
#include<queue>
#include<cstring>
#define endl "\n"
const int maxn=1e5+5,INF=0x3f3f3f3f;
typedef long long ll;
int head[maxn],nt[maxn],to[maxn],cap[maxn],cnt;
int deep[maxn],work[maxn];
int S,T,n,m;

void add(int u,int v,int w)
{
    to[cnt]=v;
    cap[cnt]=w;
    nt[cnt]=head[u];
    head[u]=cnt++;
}

bool bfs()
{
    std::queue<int> q;
    memset(deep,-1,sizeof deep);
    q.push(S);
    deep[S]=0;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=head[now];i!=-1;i=nt[i])
        {
            if(deep[to[i]]>=0||!cap[i]) continue;
            deep[to[i]]=deep[now]+1;
            if(to[i]==T) return true;
            q.push(to[i]);
        }
    }
    return false;
}

int dfs(int cur,int inc)
{
    int tinc;
    if(cur==T) return inc;
    for(int &i=work[cur];i!=-1;i=nt[i])
    {
        if(cap[i]&&deep[to[i]]==deep[cur]+1&&(tinc=dfs(to[i],std::min(inc,cap[i]))))
        {
            cap[i]-=tinc;
            cap[i^1]+=tinc;
            return tinc;
        }
    }
    return 0;
}

int dinic()
{
    int ret=0,tinc;
    while(bfs())
    {
        memcpy(work,head,sizeof head);
        while((tinc=dfs(S,INF))) ret+=tinc;
    }
    return ret;
}

int main()
{
    //freopen("test06.in","r",stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(std::cin>>m>>n)
    {
        memset(head,-1,sizeof head);
        S=1,T=n;
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            std::cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,0);
        }
        std::cout<<dinic()<<endl;
    }
}
