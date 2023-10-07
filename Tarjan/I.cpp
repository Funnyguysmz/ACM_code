#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#define endl "\n"
typedef long long ll;
const int maxn=1e5+5,maxm=1e5+5;
int n,m;
int dfn[maxn],low[maxn],scc[maxn];
int a[maxn];
int timer;
bool inst[maxn];
int head[maxn]; //头节点，这里初始化为-1表示该顶点还没有边
int to[maxm];   //该边所指向的点的编号
int nt[maxm];   //下一条边
int tot,cnt,scctot;
std::stack<int> st;

void addedge(int u,int v)
{
    to[tot]=v;
    nt[tot]=head[u];
    head[u]=tot++;
}

void tarjan(int cur)
{
    dfn[cur]=low[cur]=++timer;
    st.push(cur);
    inst[cur]=true;
    for(int i=head[cur];~i;i=nt[i])
    {
        int y=to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[cur]=std::min(low[cur],low[y]);
        }
        else if(inst[y])
        {
            low[cur]=std::min(low[cur],dfn[y]);
        }
    }
    if(dfn[cur]==low[cur])
    {
        scctot++;
        int top;
        do
        {
            top=st.top();
            st.pop();
            scc[top]=cur;
            inst[top]=false;
            if(top!=cur)
                a[cur]+=a[top];
        }while(top!=cur);
    }
}

void init()
{
    tot=scctot=timer=cnt=0;
    std::memset(head,-1,sizeof head);
    while(!st.empty())
    {
        st.pop();
    }
    for(int i=1;i<=n;++i)
    {
        dfn[i]=low[i]=scc[i]=inst[i]=a[i]=0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while(std::cin>>n>>m)
    {
    	if(!n&&!m) break;
        init();
        int x,y;
        for(int i=1;i<=m;++i)
        {
            std::cin>>x>>y;
            addedge(x,y);
        }
        for(int i=1;i<=n;++i)
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scctot==1)
        {
            std::cout<<"Yes"<<endl;
        }
        else
        {
            std::cout<<"No"<<endl;
        }
    }
    
    return 0;
}