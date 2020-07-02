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
vi order;
vi val(200001);
void dfs(ll v,ll par=-1)
{
    order.pb(v);
	for(ll d:g[v])
	{
		if(d-par)
		{
			dfs(d,v);
		}
	}
	order.pb(v);
}
namespace fenwick
{
   ll bit[500001],n;
   void upd(ll ind,ll val)
   {
	   while(ind<=n)
	   {
		   bit[ind]+=val;
		   ind+=(ind&-ind);
	   }
   }
   ll get(ll ind)
   {
	   ll res=0;
	   while(ind>=1)
	   {
		   res+=bit[ind];
		   ind-=(ind&-ind);
	   }
	   return res;
   }
}
void solve()
{
   ll n,q;
   cin>>n>>q;
   f(i,0,n)
   {
	   cin>>val[i];
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
//    f(i,0,order.size())
//    {
// 	   cout<<order[i]<<" ";
//    }
   fenwick::n=order.size();
   vector<pa>rng(n);
   f(i,0,order.size())
   {
	   if(rng[order[i]].F==0)
	   {
		   rng[order[i]].F=i+1;
	   }
	   else
	   {
		 rng[order[i]].S=i+1;
	   }
   }
   f(i,0,n)
   {
	   fenwick::upd(rng[i].F,val[i]);
       fenwick::upd(rng[i].S+1,-val[i]);
   }
   f(i,0,q)
   {
	   ll t;
	   cin>>t;
	   if(t==1)
	   {
           ll x,va;
		   cin>>x>>va;
		   x--;
		   ll ge=va-val[x];
		   val[x]=va;
		   fenwick::upd(rng[x].F,ge);
		   fenwick::upd(rng[x].S+1,-ge);
	   } 
	   else
	   {
		   ll x;
		   cin>>x;
		   x--;
		   cout<<fenwick::get(rng[x].F)<<endl;
	   }
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