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
vector<vector<ll>>dp(501,vector<ll>(501));
ll sol(ll a,ll b)
{
	if(a==b)
	{
		return 0;
	}
	if(a==0||b==0)
	{
       return 0;
	}
	if(dp[a][b])
	{
		return dp[a][b];
	}
	ll y=mod;
	f(i,1,a)
	{
       ll x=1;
	   x+=sol(i,b)+sol(a-i,b);
	   y=min(y,x);
	}
	f(i,1,b)
	{
		ll x=1;
		x+=sol(a,i)+sol(a,b-i);
		y=min(y,x);
	}
	return dp[a][b]=y;
}
void solve()
{
  ll a,b;
  cin>>a>>b;
  cout<<sol(a,b);
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

/*
*/