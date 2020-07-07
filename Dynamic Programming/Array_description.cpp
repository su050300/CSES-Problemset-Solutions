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
int n,m;
vector<int>v(100001);
vector<vector<int>>dp(100001,vector<int>(101));
void solve()
{
   cin>>n>>m;
   ll flag=0;
   f(i,0,n)
   {
	   cin>>v[i];
   }
   f(i,1,n)
   {
     if(v[i]!=0&&v[i-1]!=0&&abs(v[i]-v[i-1])>1)
	 {
		 flag=1;
	 }
   }
   if(flag)
   {
	   cout<<0;
	   return;
   }
   dp[0][0]=1;
   if(v[0]==0)
   {
	   for(int j=1;j<=m;j++)
	   {
		   dp[1][j]=1;
	   }
   }
   else
   {
	   dp[1][v[0]]=1;
   }
   for(int i=2;i<=n;i++)
   {
	   if(v[i-1]==0)
	   {
          for(int j=1;j<=m;j++)
		  {
			  if(dp[i-1][j])
			  {
			  for(int k:{j+1,j-1,j})
			  {
				  if(k>=1&&k<=m)
				  {
                     dp[i][k]+=dp[i-1][j];
					 dp[i][k]%=mod;
				  }
			  }
			  }
		  }
	   }
	   else
	   {
		   for(int j=1;j<=m;j++)
		   {
			   if(dp[i-1][j]&&abs(v[i-1]-j)<=1)
			   {
				   dp[i][v[i-1]]+=dp[i-1][j];
				   dp[i][v[i-1]]%=mod;
			   }
		   }
	   } 
   }
   ll ans=0;
   f(i,1,m+1)
   {
      ans+=dp[n][i];
	  ans%=mod;
   }
   cout<<ans<<endl;
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