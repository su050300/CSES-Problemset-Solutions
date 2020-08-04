#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>g[1000001];
vector<ll>res;
vector<ll>visited(1000001);
vector<ll>p(1000001);
void dfs(ll v,ll par=-1)
{
   if(visited[v]==2)
   {
       return;
   }
   if(visited[v]==1)
   {
       if(!res.size())
       {
          ll curr=par;
          res.push_back(v);
          while(curr!=v)
          {
              res.push_back(curr);
              curr=p[curr];
          }
          res.push_back(v);
       }
       return;
   }
   p[v]=par;
   visited[v]=1;
   for(ll d:g[v])
   {
           dfs(d,v);
   }
   visited[v]=2;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
    if(!visited[i])
    dfs(i);
    }
    if(!res.size())
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        reverse(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(ll d:res)
        {
            cout<<d+1<<" ";
        }
    }
    
    return 0;
}