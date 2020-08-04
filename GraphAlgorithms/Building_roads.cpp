#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000001];
vector<int>visited(1000001);
void dfs(int v,int par=-1)
{
    visited[v]=1;
    for(int d:g[v])
    {
        if(!visited[d])
        dfs(d,v);
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
        g[y].push_back(x);
    }
    int co=0;
    vector<pair<int,int>>res;
    int prev=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(co)
            {
                res.push_back({i+1,prev+1});
            }
            co++;
            prev=i;
            dfs(i);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}