#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace lazyseg
{
    ll tre[1000001],lazy[1000001],v[1000001];
    ll cas[1000001];
    void push(ll node,ll start,ll end)
    {
        ll mid=(start+end)/2;
        if(lazy[node])
        {
            if(start!=end)
            {
                if(cas[node]==1)
                {
                    tre[2*node+1]+=(mid-start+1)*(lazy[node]);
                    tre[2*node+2]+=(end-mid)*(lazy[node]);
                    lazy[2*node+1]+=lazy[node];
                    lazy[2*node+2]+=lazy[node];
                    if(cas[2*node+1]!=2)
                    {
                       cas[2*node+1]=1;
                    }
                    if(cas[2*node+2]!=2)
                    {
                        cas[2*node+2]=1;
                    }
                }
                else
                {
                    tre[2*node+1]=(mid-start+1)*(lazy[node]);
                    tre[2*node+2]=(end-mid)*(lazy[node]);
                    lazy[2*node+1]=lazy[2*node+2]=lazy[node];
                    cas[2*node+1]=cas[2*node+2]=2;   
                }
            }
            lazy[node]=0;
            cas[node]=0;
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
    void upd(ll node,ll start,ll end,ll l,ll r,ll val,ll t)
    {
       push(node,start,end);
       if(start>r||l>end)
        return;
       if(start>=l&&end<=r)
       {
          cas[node]=t;
          lazy[node]=val;
          if(t==1)
          {
              tre[node]+=(end-start+1)*val;
          }
          else
          {
              tre[node]=(end-start+1)*val;
          }
          push(node,start,end);
          return;
       }
       ll mid=(start+end)/2;
       upd(2*node+1,start,mid,l,r,val,t);
       upd(2*node+2,mid+1,end,l,r,val,t);
       tre[node]=tre[2*node+1]+tre[2*node+2];
    }
    ll query(ll node,ll start,ll end,ll l,ll r)
    {
        push(node,start,end);
        if(start>r||l>end)
        {
            return 0;
        }
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
           ll a,b,x;
           cin>>a>>b>>x;
           a--,b--;
           lazyseg::upd(0,0,n-1,a,b,x,t);
        }
        else if(t==2)
        {
           ll a,b,x;
           cin>>a>>b>>x;
           a--,b--;
           lazyseg::upd(0,0,n-1,a,b,x,t);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            l--,r--;
            cout<<lazyseg::query(0,0,n-1,l,r)<<endl;
        }   
    }
    return 0;
}