#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
ll n,k;
ll dp[maxn][2];
ll m[maxn];
ll a[maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        std::cin>>a[i]>>m[i];
    }
    std::memset(dp,0x3f,sizeof dp);
    dp[0][1]=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>k)
        {
            if(m[i]==1)
            {
                dp[i][1]=std::min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]-k);
                dp[i][0]=dp[i-1][1]+a[i]-k;
            }
            else
            {
                dp[i][1]=std::min(dp[i-1][1]+(a[i]-k)*m[i],dp[i-1][0]+(a[i]-k)*(m[i]-1)+a[i]);
                dp[i][0]=std::min(dp[i-1][1]+(a[i]-k)*m[i],dp[i-1][0]+(a[i]-k)*(m[i]-1)+a[i]);
            }
        }
        else
        {
            if(m[i]&1)
            {
                if(m[i]==1)
                {
                    dp[i][0]=dp[i-1][1];
                    dp[i][1]=std::min(dp[i-1][0],dp[i-1][1])+a[i];
                }
                else
                {
                    dp[i][0]=(m[i]>>1)*a[i]+std::min(dp[i-1][1],dp[i-1][0]+a[i]);
                    dp[i][1]=(m[i]>>1)*a[i]+std::min(dp[i-1][1]+a[i],dp[i-1][0]+a[i]);
                } 
            }
            else
            {
                dp[i][1]=(m[i]>>1)*a[i]+std::min(dp[i-1][1],dp[i-1][0]+a[i]);
                dp[i][0]=(m[i]>>1)*a[i]+std::min(dp[i-1][1]+a[i],dp[i-1][0]);
            }
        }
    }
    std::cout<<std::min(dp[n][0],dp[n][1])<<endl;
}