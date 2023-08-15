#include<iostream>
#include<queue>
#include<cstring>
#define endl "\n"
const int maxn=1e6+5,INF=0x3f3f3f3f;
typedef long long ll;
int head[5005],nt[maxn],to[maxn],cap[maxn],cnt;
int deep[5005],work[5005];
int S,T,n,m;

void addedge(int u,int v,int w)
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
    std::cin.tie(0);
    std::memset(head,-1,sizeof head);
    std::cin>>m>>n;
    S=0,T=m+n+10;
    int tot=0;
    for(int i=1;i<=m;++i)
    {
        int num;
        std::cin>>num;
        add(S,i,num);
        tot+=num;
        for(int j=1;j<=n;++j)
        {
            add(i,j+m,1);
        }
    }
    for(int i=1;i<=n;++i)
    {
        int c;
        std::cin>>c;
        add(i+m,T,c);
    }
    if(dinic()==tot)
    {
        std::cout<<1<<endl;
        for(int i=1;i<=m;++i)
        {
            for(int v=head[i];~v;v=nt[v])
            {
                if(!cap[v]&&to[v]!=S)
                    std::cout<<to[v]-m<<" ";
            }
            std::cout<<endl;
        }
    }
    else std::cout<<0<<endl;
}
