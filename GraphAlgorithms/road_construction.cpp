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
ll p[1000001];
ll siz[1000001];
ll find(ll v)
{
    if(p[v]!=v)
    {
        return v=find(p[v]);
    }
    return v;
}
ll ans;
void do_union(ll u,ll v)
{
    u=find(u);
    v=find(v);
    if(siz[u]>siz[v])
    {
        p[v]=u;
        siz[u]+=siz[v];
        ans=max(ans,siz[u]);
    }
    else
    {
        p[u]=v;
        siz[v]+=siz[u];
        ans=max(ans,siz[v]);
    }
}
void solve(){
   ll n,m;
   cin>>n>>m;
   f(i,0,n)
   {
       p[i]=i;
       siz[i]=1;
   }
   ll co=0;
   while(m--)
   {
     ll a,b;
     cin>>a>>b;
     a--,b--;
     if(find(a)!=find(b))
     {
     do_union(a,b);
     co++;
     }
     cout<<n-co<<" "<<ans<<endl;
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
        //  cout<<"Case #"<<i+1<<":"<<" ";
	     solve();
	// }
	return 0;
}
