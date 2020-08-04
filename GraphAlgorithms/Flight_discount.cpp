//meet-in-middle
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m;
vector<pair<ll,ll>>g[1000001];
vector<pair<ll,ll>>g1[1000001];
void di(vector<ll>&dist,ll a)
{
   ll visited[n]={0};
   priority_queue<pair<ll,ll>>q;
   q.push({-0,a});
   dist[a]=0;
   while(!q.empty())
   {
       pair<ll,ll> d=q.top();
    //    cout<<dist[d]<<" ";
       q.pop();
       if(visited[d.second])
       {
           continue;
       }
       visited[d.second]=1;
       d.first=-d.first;
       for(pair<ll,ll>ge:g[d.second])
       {
          if(dist[ge.first]==-1 || d.first+ge.second < dist[ge.first])
          {
              dist[ge.first]=d.first+ge.second;
              q.push({-(d.first+ge.second),ge.first});
          }
       }
   }
}
void di1(vector<ll>&dist,ll a)
{
   ll visited[n]={0};
   priority_queue<pair<ll,ll>>q;
   q.push({-0,a});
   dist[a]=0;
   while(!q.empty())
   {
       pair<ll,ll> d=q.top();
    //    cout<<dist[d]<<" ";
       q.pop();
       if(visited[d.second])
       {
           continue;
       }
       visited[d.second]=1;
       d.first=-d.first;
       for(pair<ll,ll>ge:g1[d.second])
       {
          if(dist[ge.first]==-1 || d.first+ge.second < dist[ge.first])
          {
              dist[ge.first]=d.first+ge.second;
              q.push({-(d.first+ge.second),ge.first});
          }
       }
   }
}
int main()
{
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edges;
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].push_back({y,w});
        g1[y].push_back({x,w});
        edges.push_back({{x,y},w});
    }
    vector<ll>a(n,-1),b(n,-1);
    di(a,0);
    di1(b,n-1);
    ll ans=1e17;
    for(int i=0;i<m;i++)
    { 
       ans=min(ans,a[edges[i].first.first]+b[edges[i].first.second]+edges[i].second/2);
    }
    cout<<ans;
    return 0;
}