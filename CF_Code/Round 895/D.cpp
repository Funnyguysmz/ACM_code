#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;
ll n,x,y;
 //2,4,6   3,6


ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		std::cin>>n>>x>>y;
		ll ans=0;
		ll div=lcm(x,y);
		ll equal=n/div;
		ll plus=n/x,minus=n/y;
		plus=std::max(0ll,plus-equal);
		minus=std::max(0ll,minus-equal);
		//std::cout<<"Debug: eq = "<<equal<<" + "<<plus<<" - "<<minus<<endl;
		if(plus)
		{
			ans+=1ll*(n+n-plus+1)*plus/2;
		}
		if(minus)
		{
			ans-=1ll*(1+minus)*minus/2;
		}
		std::cout<<ans<<endl;
	}
}
