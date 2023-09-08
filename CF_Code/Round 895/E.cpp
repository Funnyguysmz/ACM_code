#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;
int n;
std::string s;
int a[maxn];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		int val0=0;
		int val1=0;
		std::cin>>n;
		for(int i=1;i<=n;++i)
		{
			std::cin>>a[i];
		}
		std::cin>>s;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0')
				val0^=a[i+1];
			else
				val1^=a[i+1];
		}
		for(int i=1;i<=n;++i)
		{
			a[i]^=a[i-1];
		}
		int q;
		std::cin>>q;
		while(q--)
		{
			int op,l,r;
			std::cin>>op;
			if(op==1)
			{
				std::cin>>l>>r;
				val0^=a[r]^a[l-1];
				val1^=a[r]^a[l-1];
			}
			else
			{
				std::cin>>l;
				if(l==1)
					std::cout<<val1<<" ";
				else
					std::cout<<val0<<" ";
			}
		}
		std::cout<<endl;
	}
}
