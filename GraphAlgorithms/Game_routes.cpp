#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
vector<ll>g[1000001];
vector<ll>visited(1000001),dp(1000001);
ll n;
void dfs(ll v)
{
    visited[v]=1;
    if(v==n-1)
    {
       dp[v]=1;
       return;
    }
    for(ll d:g[v])
    {
        if(!visited[d])
        {
            dfs(d);
        }
        dp[v]+=dp[d];
        dp[v]%=mod;
    }
}
int main()
{
    ll m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
       ll x,y;
       cin>>x>>y;
       x--,y--;
       g[x].push_back(y);
    }
    dfs(0);
    cout<<dp[0];
    return 0;
}