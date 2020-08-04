#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>g[n];
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].push_back({y,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    vector<ll>dist(n,-1);
    map<ll,ll>minco;
    map<ll,ll>mini;
    map<ll,ll>maxi;
    for(int i=0;i<n;i++)
    {
        maxi[i]=0;
        mini[i]=mod;
    }
    q.push({0,0});
    dist[0]=0;
    minco[0]=1;
    mini[0]=1;
    maxi[0]=1;
    vector<ll>vis(n);
    while(!q.empty())
    {
        pair<ll,ll>p=q.top();
        q.pop();
        if(vis[p.second])
        {
            continue;
        }
        vis[p.second]=1;
        for(pair<ll,ll>d:g[p.second])
        {
            if(vis[d.first])
            {
                continue;
            }
            if(dist[d.first]==-1||dist[d.first]>d.second+p.first)
            {
                dist[d.first]=d.second+p.first;
                minco[d.first]=minco[p.second];
                minco[d.first]%=mod;
                mini[d.first]=mini[p.second]+1;
                maxi[d.first]=maxi[p.second]+1;
                q.push({d.second+p.first,d.first});
            }
            else if(dist[d.first]==d.second+p.first)
            {
                minco[d.first]+=minco[p.second];
                minco[d.first]%=mod; 
                mini[d.first]=min(mini[d.first],mini[p.second]+1);
                maxi[d.first]=max(maxi[d.first],maxi[p.second]+1);
            }
        }
    }
    cout<<dist[n-1]<<" "<<minco[n-1]<<" "<<mini[n-1]-1<<" "<<maxi[n-1]-1<<endl;
    return 0;
}