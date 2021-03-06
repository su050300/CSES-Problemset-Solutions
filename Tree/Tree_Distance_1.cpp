#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
#define ll long long int
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
#define vi vector<long long int> 
#define pb push_back
#define pa pair<long long int ,long long int> 
#define f(a,x,b) for(int a=x;a<b;a++)
#define sort(x) sort(x.begin(),x.end());
#define siz(a) (int)a.size()
#define mod 1000000007
#define F first
#define S second
#define um unordered_map<ll,ll>
#define ordered_set tree<pa, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
vi g[200001];
map<ll,ll>has;
pa dp[200001];
ll ans[200001];
ll roo[200001];
void dfs(ll v,ll par=-1)
{
    dp[v].F=0;
    dp[v].S=0;
    vector<ll> res;
    for(ll d:g[v])
    {
        if(d-par)
        {
            dfs(d,v);
            res.pb(dp[d].F);
        }
    }
    sort(res);
    ll n=res.size();
    if(n>=2)
    {
        dp[v]={res[n-1]+1,res[n-2]+1};
    } 
    else if(n>=1)
    {
        dp[v]={res[n-1]+1,dp[v].S};
    }
}
void reroot(ll v,ll par=-1)
{
    for(ll d:g[v])
    {
        if(d-par)
        {
            ll ge;
            if(dp[v].F==dp[d].F+1)
            {
                ge=dp[v].S+1;
            }
            else
            {
                ge=dp[v].F+1;
            }
            ans[d]=max(ge,dp[d].F);
            if(ge>dp[d].F)
            {
                dp[d].F=ge;
                dp[d].S=ge;
            }
            else
            {
                dp[d].S=max(dp[d].S,ge);
            }
            reroot(d,v);
        }
    }
}
void solve()
{
   ll n;
   cin>>n;
   f(i,0,n-1)
   {
       ll x,y;
       cin>>x>>y;
       x--,y--;
       g[x].pb(y);
       g[y].pb(x);
   }
   dfs(0);
   reroot(0);
   ans[0]=dp[0].F;
   roo[0]=dp[0].F;
   f(i,0,n)
   {
       cout<<ans[i]<<" ";
   }
}
int main() {
	fast;
	fast_input;
	fast_output;
	// ll t;
	// cin>>t;
	// f(i,0,t)
	// {
    //   cout<<"Case #"<<i+1<<":"<<" ";
	     solve();
	// }
	return 0;
}