#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=70+5,mod=10000007;
int base;
int a[maxn];
ll dp[70][1<<11][10];  //将0-10出现次数以bitset形式存在二维

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

ll lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

ll dfs(int pos,int tot,bool lead,bool limit)
{
	if(pos<0) return tot==0;
	if(~dp[pos][tot][base]&&!lead&&!limit)
		return dp[pos][tot][base];
	ll res=0;
	int up=limit?a[pos]:base-1;
	for(int i=0;i<=up;++i)
	{
		if(!i&&lead) res+=dfs(pos-1,tot,lead&&!i,limit&&i==a[pos]);
		else res+=dfs(pos-1,tot^(1<<i),lead&&!i,limit&&i==a[pos]);
	}
	if(!limit&&!lead)
		dp[pos][tot][base]=res;
	return res;
}

ll digdp(ll num)
{
	int len;
	for(len=0;num;num/=base)
		a[len++]=num%base;
	// std::cout<<"Debug: len = "<<len<<endl;
	ll ans=0;
	// std::cout<<"Debug: hightest num = "<<a[len-1]<<endl;
	ans=dfs(len-1,0,true,true);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::memset(dp,-1,sizeof dp);
	ll l,r;
	int t;
	std::cin>>t;
	while(t--)
	{
		std::cin>>base>>l>>r;
		std::cout<<digdp(r)-digdp(l-1)<<endl;
	}
	return 0;
}