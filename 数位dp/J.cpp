#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5,mod=998244353;
int dp[70][20];
int n;
ll l,r,k;
int a[70];

ll dfs(int pos,int tot,bool lead,bool limit)
{
	if(pos<0) return tot<=3;
	if(~dp[pos][tot]&&!lead&&!limit)
		return dp[pos][tot];
	ll res=0;
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;++i)
	{
		if(!i) res+=dfs(pos-1,tot,lead,limit&&i==a[pos]);
		else res+=dfs(pos-1,tot+!(i==0),lead,limit&&i==a[pos]);
	}
	if(!lead&&!limit)
		dp[pos][tot]=res;
	return res;
}

ll digdp(ll num)
{
	int len;
	for(len=0;num;num/=10)
		a[len++]=num%10;
	// std::cout<<"Debug: len = "<<len<<endl;
	ll ans=0;
	// std::cout<<"Debug: hightest num = "<<a[len-1]<<endl;
	ans=dfs(len-1,0,false,true);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::memset(dp,-1,sizeof dp);
	int t;
	std::cin>>t;
	while(t--)
	{
		std::cin>>l>>r;
		std::cout<<digdp(r)-digdp(l-1)<<endl;
	}
}