#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>g[n];
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].push_back({y,w});
    }
    vector<ll>dist(n+1,100000000000000000),visited(1000001);
    priority_queue<pair<ll,ll>>q;
    q.push({-0,0});
    dist[0]=0;
    while(!q.empty())
    {
        pair<ll,ll>d=q.top();
        q.pop();
        d.first=-d.first;
        if(visited[d.second])
        {
            continue;
        }
        visited[d.second]=1;
        for(pair<ll,ll>ge:g[d.second])
        {
            if(d.first+ge.second  < dist[ge.first])
            {
                dist[ge.first]=d.first+ge.second;
                q.push({-(d.first+ge.second),ge.first});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}