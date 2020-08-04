#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>g[1000001];
vector<ll>visited(1000001);
stack<ll>s;
ll fl,co;
void dfs(ll d)
{
   if(visited[d])
   {
       return;
   }
   visited[d]=1;
   for(ll v:g[d])
   {
           if(visited[v]==1)
           {
               fl=1;
           }
           if(!visited[v])
           {
              dfs(v);
           }
   }
   visited[d]=2;
   s.push(d);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    fl=0,co=0;
    ll has[n]={0};
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        has[y]++;
        g[x].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
        if(!has[i]&&!visited[i])
        {
            // cout<<i<<" ";
            dfs(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            fl=1;
        }
    }
    if(fl)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    while(!s.empty())
    {
        cout<<s.top()+1<<" ";
        s.pop();
    }
    return 0;
}