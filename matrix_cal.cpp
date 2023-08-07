#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
const int maxn=100+5;
const double eps=1e-6;
ll gcd(const ll &a,const ll &b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

struct matrix{
	int n;
	ll a[maxn][maxn];
	matrix(int n1)
	{
		n=n1;
	}
	matrix minus(const matrix &a,const matrix &b,ll mod)
	{
		matrix c(a.n);
		for(int i=1;i<=a.n;++i)
		{
			for(int j=1;j<=a.n;++j)
			{
				c.a[i][j]=(a.a[i][j]-b.a[i][j]+mod)%mod;
			}
		}
		return c;
	}
	matrix mul(const matrix &a,const matrix &b,ll mod)
	{
		matrix c(a.n);
		for(int i=1;i<=a.n;++i)
		{
			for(int j=1;j<=a.n;++j)
			{
				c.a[i][j]=0;
				for(int k=1;k<=a.n;++k)
				{
					c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return c;
	}
	matrix unit(int n)  //get:'nxn' '1' matrix
	{
		matrix res(n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i==j) res.a[i][j]=1;
				else res.a[i][j]=0;
			}
		}
		return res;
	}
	matrix q_pow(matrix a,ll nt,ll mod)
	{
		matrix res=unit(a.n);
		while(nt)
		{
			if(nt&1) res=mul(res,a,mod);
			a=mul(a,a,mod);
			nt>>=1;
		}
		return res;
	}
	matrix query_sum(int m,ll mod) //get:E+a^1+a^2.....+a^n
	{
		matrix res(n*2);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				res.a[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=n+1;j<=2*n;++j)
			{
				if(i==j-n) res.a[i][j]=1;
				else res.a[i][j]=0;
			}
		}
		for(int i=n+1;i<=2*n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				res.a[i][j]=0;
			}
		}
		for(int i=n+1;i<=2*n;++i)
		{
			for(int j=n+1;j<=2*n;++j)
			{
				if(i==j) res.a[i][j]=1;
				else res.a[i][j]=0;
			}
		}
		res=q_pow(res,m+1,mod);
		matrix ans(n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				ans.a[i][j]=res.a[i][j+n];
			}
		}
		return ans;
	}
	void print()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				std::cout<<a[i][j]<<' ';
			}
			std::cout<<endl;
		}
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	ll const mod=1e8;
	ll n,m;
	std::cin>>n>>m;
	n=gcd(n,m);
	matrix fib(2);
	fib.a[1][1]=0,fib.a[1][2]=1,fib.a[2][1]=1,fib.a[2][2]=1;
	fib=fib.q_pow(fib,n,mod);
	std::cout<<fib.a[1][2]<<endl;
	return 0;
}