//meet-in-middle
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>>g[n];
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].push_back({y,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,0});
    ll count[n]={0};
    vector<ll>res;
    while(!q.empty()&&count[n-1]<k)
    {
        pair<ll,ll>d=q.top();
        q.pop();
        count[d.second]++;
        if(d.second==n-1)
        {
          res.push_back(d.first);
        }
        if(count[d.second]<=k)
        {
            for(pair<ll,ll>p:g[d.second])
            {
                q.push({p.second+d.first,p.first});
            }
        }
    }
    sort(res.begin(),res.end());
    for(ll d:res)
    {
        cout<<d<<" ";
    }
    return 0;
}