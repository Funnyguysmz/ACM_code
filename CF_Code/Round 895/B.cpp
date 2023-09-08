#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;
int n;
int trap[maxn];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		std::memset(trap,0,sizeof trap);
		std::cin>>n;
		for(int i=1;i<=n;++i)
		{
			int d,s;
			std::cin>>d>>s;
			if(!trap[d]) trap[d]=s;
			trap[d]=std::min(trap[d],s);
		}
		int left=-1;
		int ans=1;
		for(int i=1;i<=200;++i)
		{
			if(left!=-1)
			{
				if(ans<i) break;
			}
			if(trap[i])
			{
				if(left==-1)
				{
					left=(trap[i]-1)/2;
					ans=i+left;
				}
				else
				{
					left=(trap[i]-1)/2;
					ans=std::min(ans,i+left);
				}
			}
		}
		std::cout<<ans<<endl;
	}
}
