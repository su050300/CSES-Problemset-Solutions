#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll tre[2000001];
vector<ll>v(2000001);
void build(ll ind,ll l,ll r)
{
    if(l==r)
    {
      tre[ind]=v[l];
    }
    else
    {
        ll mid=(l+r)/2;
        build(2*ind+1,l,mid);
        build(2*ind+2,mid+1,r);
        tre[ind]=min(tre[2*ind+1],tre[2*ind+2]);
    }
}
void upd(ll ind,ll start,ll end,ll id,ll val)
{
    if(start==end)
    {
        v[id]=val;
        tre[ind]=val;
        return;
    }
    ll mid=(start+end)/2;
    if(start<=id&&id<=mid)
    upd(2*ind+1,start,mid,id,val);
    else
    upd(2*ind+2,mid+1,end,id,val);
    tre[ind]=min(tre[2*ind+1],tre[2*ind+2]);
}
ll query(ll ind,ll start,ll end,ll l,ll r)
{
    if(r<start||l>end)
    {
        return INT_MAX;
    }
    if(l<=start&&r>=end)
    {
        return tre[ind];
    }
    ll mid=(start+end)/2;
    ll p1=query(2*ind+1,start,mid,l,r);
    ll p2=query(2*ind+2,mid+1,end,l,r);
    return min(p1,p2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    build(0,0,n-1);
    for(int i=0;i<q;i++)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
         ll pos,val;
         cin>>pos>>val;
         upd(0,0,n-1,pos-1,val);
        }
        else
        {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        cout<<query(0,0,n-1,a,b)<<endl;   
        }
    }
    return 0;
}