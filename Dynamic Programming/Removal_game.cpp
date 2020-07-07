#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v(5001);
ll co;
vector<vector<ll>>dp(5001,vector<ll>(5001,-1));
ll sol(ll l,ll r)
{
    if(l==r)
    {
       return v[l];
    }
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    ll x=0;
    ll y=0;
    x=v[l]-sol(l+1,r);
    y=v[r]-sol(l,r-1);
    return dp[l][r]=max(x,y);
}
int main()
{
    ll n;
    cin>>n;
    ll su=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        su+=v[i];
    }
    cout<<(su+sol(0,n-1))/2;
    return 0;
}