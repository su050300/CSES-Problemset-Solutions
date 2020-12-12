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
/* *** dinic algorithm *** */
namespace max_flow_graph{
    struct edge{
        ll u,v,capacity,flow;
    };
    ll n;
    vector<edge>el;
    vi g[5001];
    vi dist(5001),par(5001);
 
    void add_edge(ll u,ll v,ll w)
    {
        g[u].pb(el.size());
        el.pb({u,v,w,0});
        g[v].pb(el.size());
        el.pb({v,u,0,0});
    }
 
    int send_one_flow(ll s,ll e)
    {
         ll mini=1e9;
         for(int u=e;u!=s;u=el[par[u]].u)
         {
            mini=min(mini,el[par[u]].capacity-el[par[u]].flow);
         }
 
         for(int u=e;u!=s;u=el[par[u]].u)
         {
            el[par[u]].flow+=mini;
            el[par[u]^1].flow-=mini;
         }
         return mini;
    }
 
    bool bfs(ll s,ll e)
    {
        dist.assign(n+1,1e9);
        par.assign(n+1,0);
        queue<ll>q;
        q.push(s);
        dist[s]=0;
        while(q.size())
        {
            int u=q.front();
            q.pop();
            if(u==e)
            {
                break;
            }
            for(ll idx:g[u])
            {
                if(el[idx].capacity>el[idx].flow&&dist[el[idx].v]>dist[el[idx].u]+1)
                {
                    dist[el[idx].v]=dist[el[idx].u]+1;
                    par[el[idx].v]=idx;
                    q.push(el[idx].v);
                }
            }
        }
        return dist[e]<1e9;
    }
 
    ll dfs(ll s,ll e,ll f=1e9)
    {
        if(s==e || f==0)
        return f;
        for(ll idx:g[s])
        {
            if(dist[el[idx].v]!=dist[s]+1) 
            continue;
            if(ll nf=dfs(el[idx].v,e,min(f,el[idx].capacity-el[idx].flow)))
            {
                el[idx].flow+=nf;
                el[idx^1].flow-=nf;
                return nf;
            }
        }
        return 0;
    }
    ll dinic(ll s,ll e)
    {
        ll mf=0;
        while(bfs(s,e))
        {
            while(ll nf=dfs(s,e))
            mf+=nf;
        }
        return mf;
    }
};
vi ge[1001];
vii res;
map<pa,ll>mp;
void dfs1(ll v,vi vo)
{
   vo.pb(v);
   if(v==max_flow_graph::n -1)
   {
       f(i,1,vo.size())
       {
           if(mp.find({vo[i-1],vo[i]})==mp.end())
           {
           }
           else
           {
            //    cout<<vo[i-1]<<" "<<vo[i]<<endl;
               return;
           }
       }
       f(i,1,vo.size())
       {
           mp[{vo[i-1],vo[i]}]=1;
       }
       res.pb(vo);
       return;
   }
   for(ll d:ge[v])
   {
      dfs1(d,vo);
   }
}
void solve(){
   ll n,m;
   cin>>n>>m;
   max_flow_graph::n=n;
   f(i,0,m)
   {
       ll u,v,w;
       cin>>u>>v;
       u--,v--;
       w=1;
       max_flow_graph::add_edge(u,v,w); 
   }
   cout<<max_flow_graph::dinic(0,n-1)<<endl; 
   f(i,0,max_flow_graph::el.size())
   {
       if(max_flow_graph::el[i].flow==-1)
       {
           ge[max_flow_graph::el[i].v].pb(max_flow_graph::el[i].u);
       }
    //    cout<<max_flow_graph::el[i].u<<" "<<max_flow_graph::el[i].v<<" "<<max_flow_graph::el[i].capacity<<" "<<max_flow_graph::el[i].flow<<endl;
   }  
   vector<ll>vo;
   dfs1(0,vo);
   for(auto d:res)
   {
       cout<<d.size()<<endl;
       for(auto re:d)
       {
           cout<<re+1<<" ";
       }
       cout<<endl;
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