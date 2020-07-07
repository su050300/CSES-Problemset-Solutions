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
void solve()
{
   ll n;
   cin>>n;
   vi v(6);
   f(i,0,6)
   {
	   v[i]=i+1;
   }
   vector<ll>dp(n+1);
   dp[0]=1;
   for(int j=1;j<=n;j++)
   {
	   for(int i=0;i<6;i++)
	   {
		   if(j-v[i]>=0)
		   {
			   dp[j]+=dp[j-v[i]];
			   dp[j]%=mod;
		   }
	   }
   }
   cout<<dp[n];
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