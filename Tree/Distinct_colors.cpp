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
unordered_set<ll>so;
ll val[200001];
ll c[200001];
void dfs(ll v,ll par=-1)
{
	unordered_set<ll>t;
	t.insert(c[v]);
	for(ll d:g[v])
	{
		if(d-par)
		{
			dfs(d,v);
			if(so.size()>t.size())
			{
               swap(so,t);
			}
			for(auto d:so)
			{
				t.insert(d);
			}
		}
	}
	val[v]=t.size();
	swap(so,t);
}
void solve()
{
   ll n;
   cin>>n;
   f(i,0,n)
   {
	   cin>>c[i];
   }
   f(i,1,n)
   {
	  ll x,y;
	  cin>>x>>y;
	  x--,y--;
	  g[x].pb(y);
	  g[y].pb(x);
   }
   dfs(0);
   f(i,0,n)
   {
	   cout<<val[i]<<" ";
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
	