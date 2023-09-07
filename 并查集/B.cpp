#include<iostream>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int n,m;
int f[maxn];

void init()
{
	for(int i=1;i<=n*2;++i) f[i]=i;
}

int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int a,int b)
{
	f[find(a)]=find(b);
}

int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;++i)
		{
			char s[3];
			int u,v;
			scanf("%s%d%d",s,&u,&v);
			if(s[0]=='D')
			{
				merge(u+n,v),merge(u,v+n);
			}
			else
			{
				//std::cout<<"ok"<<endl;
				if(find(u)==find(v))
				{
					printf("In the same gang.\n");
				}
				else if(find(u)==find(v+n))
				{
					printf("In different gangs.\n");
				}
				else
				{
					printf("Not sure yet.\n");
				}
			}
		}
	}
	return 0;
}