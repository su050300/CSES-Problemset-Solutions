#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000001];
vector<int>dist(1000001,-1),visited(1000001),path(1000001,-1);
int n;
void dfs(int v)
{
    visited[v]=1;
    if(v==n-1)
    {
        dist[v]=0;
        return;
    }
    for(int d:g[v])
    {
        if(!visited[d])
        {
            dfs(d);
        }
        if(dist[d]!=-1&&dist[v] < dist[d]+1)
        {
            dist[v]=dist[d]+1;
            path[v]=d;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
    }
    dfs(0);
    if(path[0]==-1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int>res;
    res.push_back(0);
    int curr=path[0];
    while(curr!=-1)
    {
        res.push_back(curr);
        curr=path[curr];
    }
    cout<<res.size()<<endl;
    for(int d:res)
    {
        cout<<d+1<<" ";
    }
    return 0;
}