#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=1e5+5,mod=1e8;
int n,k;
int a[maxn];
int ss[maxn],c[maxn];
int dp[15][1<<13];

// bool check(int x,int st)
// {
// 	for(int i=0;i<n;++i)
// 	{
// 		if((st&(1<<i))&&a[x][i+1]==0)
// 			return false;
// 	}
// 	return true;
// }

// int cal(ll num)
// {
// 	int tot=0;
// 	whle(num)
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
	std::cin>>k>>n;
	for(int i=1;i<=k;++i)
	{
		std::cin>>c[i];
	}
	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i];
	}
	if(1)
	{
		std::cout<<"-1"<<endl;
		return 0;
	}
	return 0;
}