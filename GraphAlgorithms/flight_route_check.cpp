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
#define vii vector<vi>
#define vp vector<pair<ll,ll>>
#define vpp vector<pair<ll,pair<ll,ll>>>
#define pb push_back
#define pu push
#define po pop
#define up(v,x) upper_bound(v.begin(),v.end(),x)
#define lo(v,x) lower_bound(v.begin(),v.end(),x)
#define ups(v,x) v.upper_bound(x)
#define los(v,x) v.loer_bound(x)
#define pa pair<long long int ,long long int> 
#define f(a,x,b) for(int a=x;a<b;a++)
#define fr(a,x,b) for(int a=x;a>=b;a--)
#define sort(x) sort(x.begin(),x.end())
#define rev(x) reverse(x.begin(),x.end())
#define sz(a) (int)a.size()
#define mod 1000000007
#define F first
#define S second
#define um unordered_map<ll,ll>
#define ordered_set tree<pa, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update
vi g[100001],ge[100001];
ll vis[100001];
void dfs(ll v)
{
   vis[v]=1;
   for(ll d:g[v])
   {
       if(!vis[d])
       {
           dfs(d);
       }
   }
}
void dfs1(ll v)
{
    vis[v]=1;
    for(ll d:ge[v])
    {
        if(!vis[d])
        {
            dfs1(d);
        }
    }
}
void solve(){
   ll n,m;
   cin>>n>>m;
   f(i,0,m)
   {
       ll x,y;
       cin>>x>>y;
       x--,y--;
       g[x].pb(y);
       ge[y].pb(x);
   }
   dfs(0);
   f(i,0,n)
   {
       if(!vis[i])
       {
           cout<<"NO"<<endl;
           cout<<1<<" "<<i+1<<endl;
           return;
       }
   }
   memset(vis,0,sizeof(vis));
   dfs1(0);
   f(i,0,n)
   {
       if(!vis[i])
       {
           cout<<"NO"<<endl;
           cout<<i+1<<" "<<1<<endl;
           return;
       }
   }
   cout<<"YES"<<endl;
}
int main() {
	fast;
	fast_input;
	fast_output;
	// ll t;
	// cin>>t;
	// f(i,0,t)
	// {
        //  cout<<"Case #"<<i+1<<":"<<" ";
	     solve();
	// }
	return 0;
}
