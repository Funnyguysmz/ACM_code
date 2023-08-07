#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=100+5,mod=1e8;
int n,m;
int a[15][15];
int ss[1<<13];
int dp[15][1<<13];

bool check(int x,int st)
{
	for(int i=0;i<n;++i)
	{
		if((st&(1<<i))&&a[x][i+1]==0)
			return false;
	}
	return true;
}

// int cal(ll num)
// {
// 	int tot=0;
// 	while(num)
// 	{
// 		tot+=num&1;
// 		num>>=1;
// 	}
// 	return tot;
// }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>m>>n;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			std::cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<(1<<n);++i)
	{
		if(!(i&(i<<1)))
			ss[++cnt]=i;
	}
	for(int i=1;i<=cnt;++i)
	{
		if(check(1,ss[i]))
			dp[1][i]=1;
	}
	for(int i=2;i<=m;++i)
	{
		for(int j=1;j<=cnt;++j)
		{
			if(check(i,ss[j]))
			{
				for(int k=1;k<=cnt;++k)
				{
					if(!(ss[j]&ss[k]))
						dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;++i)
	{
		ans=(ans+dp[m][i])%mod;
	}
	// for(int i=1;i<=m;++i)
	// {
	// 	for(int j=1;j<=cnt;++j)
	// 	{
	// 		std::cout<<dp[i][j]<<' ';
	// 	}
	// 	std::cout<<endl;
	// }
	std::cout<<ans<<endl;
	return 0;
}