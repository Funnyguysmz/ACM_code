#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;
ll n;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		std::cin>>n;
		ll ans=(1ll+n)*n/2ll;
		ll v=1;
		while(v<=n)
		{
			ans-=(v<<1);
			v<<=1;
		}
		std::cout<<ans<<endl;
	}
}