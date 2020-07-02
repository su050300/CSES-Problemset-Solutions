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
ll sparse[200001][22];
void dfs(ll v,ll par=-1)
{
    sparse[v][0]=par;
	for(ll d:g[v])
	{
		if(d-par)
		{
			dfs(d,v);
		}
	}
}
void solve()
{
   ll n,q;
   cin>>n>>q;
   f(i,1,n)
   {
	  ll x;
	  cin>>x;
	  x--;
	  g[x].pb(i);
	  g[i].pb(x);
   }
   for(int i=0;i<n;i++)
   {
	   for(int j=0;j<22;j++)
	   {
		   sparse[i][j]=-1;
	   }
   }
   dfs(0);
   ll maxi=log2(n);
   for(int i=1;i<=maxi;i++)
   {
	   for(int j=0;j<n;j++)
	   {
		   if(sparse[j][i-1]!=-1)
		   {
              ll par=sparse[j][i-1];
			  sparse[j][i]=sparse[par][i-1];
		   } 
	   }
   }
//    for(int i=0;i<n;i++)
//    {
// 	   for(int j=0;j<maxi;j++)
// 	   {
// 		   cout<<sparse[i][j]<<" ";
// 	   }
// 	   cout<<endl;
//    }
   f(i,0,q)
   {
	   ll x,k;
	   cin>>x>>k;
       x--;
	   ll ans=-1;
	   while(k)
	   {
		 if(k==1)
		 {
			 ans=sparse[x][0];
			 break;
		 }
         ll ma=log2(k);
		//  cout<<ma<<" ";
         ans=sparse[x][ma];
		 if(ans==-1)
		 {
			 break;
		 }
		 k-=(1<<ma);
		 x=ans;
	   }
	   if(ans==-1)
	   {
		   cout<<ans<<endl;
	   }
	   else
	   cout<<ans+1<<endl;
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