#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edges;
    ll flag=0;
    set<ll>s;
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        edges.push_back({{x,y},-w});
        s.insert(w);
    }
    if(s.size()>1)
     flag=1;
    ll ans=0;
    vector<ll>dist(n,10000000000000000);
    ll fl=0;
    dist[0]=0;
    ll pre=0;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
          if(dist[edges[j].first.second] > dist[edges[j].first.first]+edges[j].second)
          {
          dist[edges[j].first.second]=dist[edges[j].first.first]+edges[j].second;
          if(i==n-1)
          {
              fl=1;
          }
          }
       }
    }
    if(fl&&flag)
    {
        cout<<-1;
    }
    else
    {
        cout<<(-dist[n-1]);
    }
    
    return 0;
}