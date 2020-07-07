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
   string s;
   string t;
   cin>>s;
   cin>>t;
   vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1));
   f(i,0,s.length()+1)
   {
     dp[i][0]=i;
   }
   f(j,0,t.length()+1)
   {
	   dp[0][j]=j;
   }
   f(i,1,s.length()+1)
   {
	   f(j,1,t.length()+1)
	   {
		   if(s[i-1]==t[j-1])
		   {
			   dp[i][j]=dp[i-1][j-1];
		   }
		   else
		   {
			   dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
		   }
	   }
   }
   cout<<dp[s.length()][t.length()];
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