#include<iostream>
#include<queue>
#include<cstring>
#define endl "\n"
const int maxn=3e5+5,INF=0x3f3f3f3f;
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
    int t;
    int count=1;
    std::cin>>t;
    while(t--)
    {
        cnt=0;
        int tot=0;
        std::memset(head,-1,sizeof head);
        std::cin>>n>>m;
        S=(505<<1)+5,T=(505<<1)+10;
        for(int i=1;i<=n;++i)
        {
            int si,pi,ei;
            std::cin>>pi>>si>>ei;
            tot+=pi;
            add(S,i,pi);
            for(int j=si;j<=ei;++j)
            {
                add(i,j+505,1);
            }
        }
        for(int i=506;i<=(505<<1);++i)
        {
            add(i,T,m);
        }
        int ans=dinic();
        std::cout<<"Case "<<count++<<": ";
        if(ans==tot) std::cout<<"Yes"<<endl;
        else std::cout<<"No"<<endl;
        std::cout<<endl;
    }
}
