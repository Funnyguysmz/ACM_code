#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5,maxm=2e5+5;
int n,m;
int dfn[maxn],low[maxn];
int timer;
bool iscut[maxn];
int head[maxn]; //头节点，这里初始化为-1表示该顶点还没有边
int to[maxm];   //该边所指向的点的编号
int nt[maxm];   //下一条边
int tot,cnt,root;

void addedge(int u,int v)
{
    to[tot]=v;
    nt[tot]=head[u];
    head[u]=tot++;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++timer;
	int son=0;
	for(int i=head[x];~i;i=nt[i])
	{
		int y=to[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=std::min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				++son;
				if(x!=root||son>1)
				{
					cnt+=!iscut[x];
					iscut[x]=true;
				}
			}
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
	std::cin>>n>>m;
	std::memset(head,-1,sizeof head);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		std::cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			root=i;
			tarjan(i);
		}
	}
	std::cout<<cnt<<endl;
	for(int i=1;i<=n;++i)
	{
		if(iscut[i])
			std::cout<<i<<' ';
	}
	return 0;
}