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
    ll n,x;
	cin>>n>>x;
	vector<vector<int>>dp(n+1,vector<int>(x+1));
	vector<int> price(n);
	f(i,0,n)
	{
       cin>>price[i];
	}
	vector<int> pages(n);
	f(i,0,n)
	{
      cin>>pages[i];
	}
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(j-price[i-1]>=0)
			{
				dp[i][j]=max(dp[i-1][j],pages[i-1]+dp[i-1][j-price[i-1]]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int ans=0;
	f(j,1,x+1)
	{
		ans=max(ans,dp[n][j]);
	}
	cout<<ans;
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