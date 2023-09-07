#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5,maxm=5e5+5;
int n,m;
int dfn[maxn],low[maxn];
int timer;
bool iscut[maxn];
int head[maxn]; //头节点，这里初始化为-1表示该顶点还没有边
int to[maxm];   //该边所指向的点的编号
int nt[maxm];   //下一条边
int tot,cnt,root;
int l,r;

void addedge(int u,int v)
{
    to[tot]=v;
    nt[tot]=head[u];
    head[u]=tot++;
}

void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++timer;
	int son=0;
	for(int i=head[x];~i;i=nt[i])
	{
		int y=to[i];
		if(y==fa) continue;
		if(!dfn[y])
		{
			tarjan(y,x);
			if(low[y]>=dfn[x])
			{
				++son;
				if((x!=root||son>1)&&dfn[r]>=dfn[y])
				{
					cnt+=!iscut[x];
					iscut[x]=true;
				}
			}
			low[x]=std::min(low[x],low[y]);
		}
		else
		{
			low[x]=std::min(low[x],dfn[y]);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>n;
	std::memset(head,-1,sizeof head);
	int x,y;
	while(std::cin>>x>>y&&x&&y)
	{
		addedge(x,y);
		addedge(y,x);
	}
	std::cin>>l>>r;
	root=l;	
	tarjan(l,0);
	for(int i=1;i<=n;++i)
	{
		if(iscut[i])
		{
			std::cout<<i<<endl;
			return 0;
		}
	}
	std::cout<<"No solution"<<endl;
	return 0;
}