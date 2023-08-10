#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=70+5,mod=10000007;
int a[maxn];
ll dp[25][2525][50];
std::unordered_map<int,int> mmp;

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

ll lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

ll dfs(int pos,int pre,int m,bool lead,bool limit)
{
	if(pos<0) return (pre%m==0);
	if(~dp[pos][pre][mmp[m]]&&!lead&&!limit)
		return dp[pos][pre][mmp[m]];
	ll res=0;
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;++i)
	{
		if(!i) res+=dfs(pos-1,pre*10%2520,m,false,limit&&(i==a[pos]));
		else res+=dfs(pos-1,(pre*10+i)%2520,lcm(i,m),false,limit&&(i==a[pos]));
	}
	if(!limit&&!lead)
		dp[pos][pre][mmp[m]]=res;
	return res;
}

ll digdp(ll num)
{
	int len;
	for(len=0;num;num/=10)
		a[len++]=num%10;
	// std::cout<<"Debug: len = "<<len<<endl;
	// std::cout<<"Debug: hightest num = "<<a[len-1]<<endl;
	return dfs(len-1,0,1,false,true);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int q;
	std::cin>>q;
	while(q--)
	{
		int b,l,r;
		std::cin>>b>>l>>r;
		
	}
	return 0;
}