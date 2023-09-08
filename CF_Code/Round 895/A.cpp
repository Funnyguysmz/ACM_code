#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		int a,b,c;
		std::cin>>a>>b>>c;
		double tot=std::abs(b-a);
		tot/=2.0;
		int ans=0;
		while(tot>0)
		{
			tot-=c;
			++ans;
		}
		std::cout<<ans<<endl;
	}
}
