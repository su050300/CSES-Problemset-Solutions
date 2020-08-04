#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000001];
vector<int>visited(1000001);
vector<int>par(1000001,-1);
vector<int>res;
void dfs(int v,int pa=-1)
{
    if(visited[v]==2)
      return;
    if(visited[v]==1)
    {
       if(!res.size())
       {
       int curr=pa;
       res.push_back(v);
    //    set<int>s;
       while(curr!=v)
       {
        //    cout<<curr<<" ";
           res.push_back(curr);
           curr=par[curr];
       }
       res.push_back(v);
       }
       return;
    }
    par[v]=pa;
    visited[v]=1;
    for(int d:g[v])
    {
        if(d-pa)
        {
            dfs(d,v);
        }
    }
    visited[v]=2;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
    if(!visited[i])
    dfs(i);
    }
    if(res.size())
    {
    cout<<res.size()<<endl;
    for(auto d:res)
    {
        cout<<d+1<<" ";
    }
    }
    else
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}