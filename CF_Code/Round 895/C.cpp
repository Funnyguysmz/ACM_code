#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=2e5+5;
int t;

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

int isprime(int num)
{
	if(num==1) return -1;
	for(int i=2;i<=std::sqrt(num);++i)
	{
		if(num%i==0) return i;
	}
	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>t;
	while(t--)
	{
		int l,r;
		std::cin>>l>>r;
		if(l%2==0&&l!=2) std::cout<<l/2<<' '<<l/2<<endl;
		else if(r%2==0&&r!=2) std::cout<<r/2<<' '<<r/2<<endl;
		else if(r-l>=2&&l>=2)
		{
			std::cout<<(l/2+1)<<' '<<(l/2+1)<<endl;
		}
		else if(r-l>2)
		{
			std::cout<<(l+3)/2<<' '<<(l+3)/2<<endl;
		}
		else
		{
			int a=isprime(l),b=isprime(r);
			if(a!=-1)
			{
				std::cout<<l/a<<' '<<l-(l/a)<<endl;
				// std::cout<<"Debug:gcd = "<<gcd(l/a,l-(l/a))<<endl;
			}
			else if(b!=-1)
			{
				std::cout<<r/b<<' '<<r-(r/b)<<endl;
				// std::cout<<"Debug:gcd = "<<gcd(r/b,r-(r/b))<<endl;
			}
			else
			{
				std::cout<<"-1"<<endl;
			}
		}
	}
}
