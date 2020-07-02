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
ll level[200001];
void dfs(ll v,ll par=-1)
{
    sparse[v][0]=par;
	if(par!=-1)
	{
		level[v]=level[par]+1;
	}
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
	  ll x,y;
	  cin>>x>>y;
	  x--,y--;
	  g[x].pb(y);
	  g[y].pb(x);
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
   f(i,0,q)
   {
	   ll a,b;
	   cin>>a>>b;
	   a--,b--;
	   ll strt=a;
	   ll en=b;
       if(level[a]>level[b])
	   {
		   swap(a,b);
	   }
	   ll d=(level[b]-level[a]);
	   ll ans=b;
	   while(d)
	   {
         if(d==1)
		 {
			 ans=sparse[b][0];
			 break;
		 }
		 ll maxi=log2(d);
		 ans=sparse[b][maxi];
		 d-=(1<<maxi);
		 b=ans;
	   }
	//    cout<<a<<" "<<ans<<" ";
	   if(a==ans)
	   {
		   cout<<abs(level[strt]-level[en])<<endl;
		   continue;
	   }
	   for(int j=21;j>=0;j--)
	   {
		   if(sparse[a][j]!=-1&&sparse[ans][j]!=sparse[a][j])
		   {
			   a=sparse[a][j];
			   ans=sparse[ans][j];
		   }
	   }
	   cout<<abs(level[sparse[a][0]]-level[strt])+abs(level[sparse[a][0]]-level[en])<<endl;
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