/*kosaraju algorithm using two dfs to determine the connected components use of stack to determine the order 
of vertices in which we need to detrmine the components*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000001],g1[1000001];
vector<int> visited(1000001);
vector<int> ans(1000001,-1);
stack<int>s;
void dfs(int v)
{
    visited[v]=1;
    for(int d:g[v])
    {
        if(!visited[d])
        dfs(d);
    }
    s.push(v);
}
int coo;
void dfs1(int v)
{
    ans[v]=coo;
    visited[v]=1;
    for(int d:g1[v])
    {
        if(!visited[d])
        dfs1(d);
    }
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
        g1[y].push_back(x);
    }  
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    while(!s.empty())
    {
        int d=s.top();
        s.pop();
        if(!visited[d])
        {
            dfs1(d);
            coo++;
        }
    }
    cout<<coo<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]+1<<" ";
    }
    return 0;
}