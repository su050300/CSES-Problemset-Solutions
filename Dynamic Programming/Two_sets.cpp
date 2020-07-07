#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<vector<ll>>dp(500+1,vector<ll>(90000+1,-1));
ll powmod(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b%2)
        {
            res*=a;
        }
        a=a*a;
        res%=mod;
        a%=mod;
        b/=2;
    }
    return res;
}
ll sol(ll n,ll ge)
{
    if(ge==0)
    {
        return 1;
    }
    if(n<=0)
    {
        return 0;
    }
    if(dp[n][ge]!=-1)
     return dp[n][ge];
    // cout<<n<<" "<<ge<<endl;
    ll x=0,y=0;
    x+=sol(n-1,ge);
    if(ge>=n)
    {
        y+=sol(n-1,ge-n);
    }
    return dp[n][ge]=((x+y)%mod);
}
int main()
{
    ll n;
    cin>>n;
    ll ge=(n*(n+1))/2;
    if(ge%2)
    {
        cout<<0<<endl;
    }
    else
    {
        // cout<<powmod(2,mod-2)<<endl;
        cout<<(sol(n,ge/2)*powmod(2,mod-2))%mod;
    }
    return 0;
}