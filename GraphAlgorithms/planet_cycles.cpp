#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000001],g1[1000001];
vector<int> visited(1000001,-1);
int incyc[1000001];
vector<int> ans(1000001,-1);
int dfs(int v,int p)
{
    if(visited[v]!=-1)
    {
        if(visited[v]==p)
        {
            return v;
        }
        return -1;
    }
    visited[v]=p;
    for(int d:g[v])
    {
        return dfs(d,p);
    }
}
void dfs1(int v)
{
    for(int d:g1[v])
    {
        if(!incyc[d])
        {
            ans[d]=ans[v]+1;
            dfs1(d);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        x--;
        g[i].push_back(x);
        g1[x].push_back(i);
    }  
    for(int i=0;i<n;i++)
    {
        if(visited[i]==-1)
        {
            int x=dfs(i,i);
            vector<int>cyc;
            if(x!=-1)
            {
                while(visited[x]==i)
                {
                    visited[x]=INT_MAX;
                    cyc.push_back(x);
                    for(int d:g[x])
                    {
                        x=d;
                    }
                }
                for(int d:cyc)
                {
                    incyc[d]=1;
                    ans[d]=cyc.size();
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(incyc[i])
        {
            dfs1(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}