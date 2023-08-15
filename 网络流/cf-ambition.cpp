#include<bits/stdc++.h>
#define endl "\n"
const int maxn=5e5+5,INF=0x3f3f3f3f;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(head,-1,sizeof head);
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int num;
        std::cin>>num;
        for(int j=1;j<=num;++j)
        {
            int v;
            std::cin>>v;
            add(i,v+n,1);
            add(v+n,i,0);
        }
    }
    S=n+m+1;
    T=S+1;
    for(int i=1;i<=n;++i)
    {
        add(S,i,1);
        add(i,S,0);
    }
    for(int i=1;i<=m;++i)
    {
        add(i+n,T,1);
        add(T,i+n,0);
    }
    std::cout<<m-dinic()<<endl;
}
