#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll id;
namespace segment
{
    ll tre[1000001],v[1000001];
    void build(ll node,ll l ,ll r)
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
           tre[node]=max(tre[2*node+1],tre[2*node+2]);   
        }
    }
    void upd(ll node,ll start,ll end,ll idx,ll val)
    {
        if(start==end)
        {
            v[idx]=val;
            tre[node]=val;
        }
        else
        {
           ll mid=(start+end)/2;
           if(idx>=start&&idx<=mid)
           {
              upd(2*node+1,start,mid,idx,val);
           } 
           else
           {
              upd(2*node+2,mid+1,end,idx,val);
           }
           tre[node]=max(tre[2*node+1],tre[2*node+2]);
        } 
    }
    void query(ll node,ll start,ll end,ll val)
    {
         if(start==end)
         {
            if(tre[node]>=val)
            id=start;
         }
         else
         {
            ll mid=(start+end)/2;
            ll idx=0;
            if(tre[2*node+1]>=val)
            {
               query(2*node+1,start,mid,val);
            }   
            else if(tre[2*node+2]>=val)
            {
                query(2*node+2,mid+1,end,val);
            }
         } 
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>segment::v[i];
    }
    segment::build(0,0,n-1);
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        id=-1;
        segment::query(0,0,n-1,x);
        if(id==-1)
        {
           cout<<0<<" ";
        }
        else
        {
           cout<<id+1<<" ";
           segment::upd(0,0,n-1,id,segment::v[id]-x);   
        }
    }
    return 0;
}
