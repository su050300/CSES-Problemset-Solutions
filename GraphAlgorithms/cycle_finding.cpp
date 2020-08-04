#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edge;
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        edge.push_back({{x,y},w});
    }
    vector<ll>dist(n,1e17);
    dist[0]=0;
    vector<ll>par(n,-1);
    ll isnegcy;
    for(int i=0;i<n;i++)
    {
        isnegcy=-1;
        for(int j=0;j<m;j++)
        {
            ll x=edge[j].first.first;
            ll y=edge[j].first.second;
            if(dist[y] > dist[x]+edge[j].second)
            {
                dist[y]=dist[x]+edge[j].second;
                isnegcy=x;
                par[y]=x;
            }
        }
    }
    if(isnegcy==-1)
    {
       cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            isnegcy=par[isnegcy];
        }
        vector<int>res;
        res.push_back(isnegcy);
        ll curr=par[isnegcy];
        while(curr!=isnegcy)
        {
            res.push_back(curr);
            curr=par[curr];
        }
        res.push_back(isnegcy);
        reverse(res.begin(),res.end());
        for(ll d:res)
        {
            cout<<d+1<<" ";
        }
    }
    return 0;
}