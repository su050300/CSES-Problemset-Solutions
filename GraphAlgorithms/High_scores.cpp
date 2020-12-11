#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e14
ll chk[100001],chk1[100001];
vector<ll>g[100001],gr[100001];
void dfs(ll v)
{
   chk[v]=1;
   for(ll d:g[v])
   {
       if(!chk[d])
       {
           dfs(d);
       }
   }
}
void dfs1(ll v)
{
   chk1[v]=1;
   for(ll d:gr[v])
   {
       if(!chk1[d])
       {
           dfs1(d);
       }
   }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edges;
    set<ll>s;
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].push_back(y);
        gr[y].push_back(x);
        edges.push_back({{x,y},-w});
    }
    dfs(0);
    dfs1(n-1);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<chk[i]<<" "<<chk1[i]<<endl;
    // }
    vector<ll>dist(n,mod);
    ll fl=0;
    dist[0]=0;
    ll pre=0;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
          if(chk[edges[j].first.first]&&chk1[edges[j].first.second]&&dist[edges[j].first.second] > dist[edges[j].first.first]+edges[j].second)
          {
          dist[edges[j].first.second]=dist[edges[j].first.first]+edges[j].second;
          if(i==n-1)
          {
              fl=1;
          }
          }
       }
    }
    if(fl)
    {
        cout<<-1;
    }
    else
    {
        cout<<(-dist[n-1]);
    }
    
    return 0;
}