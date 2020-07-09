#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace lazyseg
{
    ll tre[1000001],v[1000001];
    pair<ll,ll>po[1000001];
    void push(ll node,ll l,ll r)
    {
        ll mid=(l+r)/2;
        if(l!=r)
        {
           if(po[node].first!=0||po[node].second!=0)
           {
              po[2*node+1].first+=po[node].first;
              po[2*node+1].second+=po[node].second;
              tre[2*node+1]+=((mid-l)*(mid-l+1)/2 * po[node].first)+ (mid-l+1)*po[node].second;
              po[2*node+2].first+=po[node].first;
              ll ge=po[node].second+(mid-l+1)*po[node].first;
              po[2*node+2].second+=ge;
              tre[2*node+2]+=((r-mid)*(r-mid-1)/2 * po[node].first)+ (r-mid)*ge;
           }
           po[node]={0,0};
        }
    }
    void build(ll node,ll l,ll r)
    {
        if(l==r)
        {
            tre[node]=v[l];
        }
        else
        {
            ll mid=(l+r)/2;
            build(2*node+1,l,mid);
            build(2*node+2,mid+1,r);
            tre[node]=tre[2*node+1]+tre[2*node+2];
        }
    }
    void upd(ll node,ll start,ll end,ll l,ll r)
    {
       push(node,start,end);
       if(start>r||l>end)
        return;
       if(start>=l&&end<=r)
       {
           ll lo=(start-l+1);
           ll hi=(end-l+1);
           tre[node]+=((hi*(hi+1))/2-(lo*(lo-1))/2);
           po[node].first=1,po[node].second=lo;
           push(node,start,end);
           return;
       }
       push(node,start,end);
       ll mid=(start+end)/2;
       upd(2*node+1,start,mid,l,r);
       upd(2*node+2,mid+1,end,l,r);
       tre[node]=tre[2*node+1]+tre[2*node+2];
    }
    ll query(ll node,ll start,ll end,ll l,ll r)
    {
        if(start>r||l>end)
        {
            return 0;
        }
        push(node,start,end);
        if(start>=l&&end<=r)
        {
            return tre[node];
        }
        ll mid=(start+end)/2;
        ll p1=query(2*node+1,start,mid,l,r);
        ll p2=query(2*node+2,mid+1,end,l,r);
        return p1+p2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>lazyseg::v[i];
    }
    lazyseg::build(0,0,n-1);
    while(q--)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll a,b;
            cin>>a>>b;
            a--,b--;
            lazyseg::upd(0,0,n-1,a,b);
        }
        else
        {
            ll a,b;
            cin>>a>>b;
            a--,b--;
            cout<<lazyseg::query(0,0,n-1,a,b)<<"\n";
        }
    }
    return 0;
}