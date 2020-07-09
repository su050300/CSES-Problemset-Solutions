#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace segment
{
    struct subaray
    {
        ll sum;
        ll pr;
        ll sr;
        ll maxi;
    }tre[1000001];
    ll v[1000001];
    void build(ll node,ll l,ll r)
    {
        if(l==r)
        {
            tre[node].sum=v[l];
            tre[node].pr=v[l];
            tre[node].sr=v[l];
            tre[node].maxi=v[l];
        }
        else
        {
            ll mid=(l+r)/2;
            build(2*node+1,l,mid);
            build(2*node+2,mid+1,r);
            tre[node].sum=tre[2*node+1].sum+tre[2*node+2].sum;
            tre[node].pr=max(tre[2*node+1].sum+tre[2*node+2].pr,tre[2*node+1].pr);
            tre[node].sr=max(tre[2*node+1].sr+tre[2*node+2].sum,tre[2*node+2].sr);
            tre[node].maxi=max({tre[2*node+1].maxi,tre[2*node+2].maxi,tre[2*node+1].sr+tre[2*node+2].pr
            ,tre[node].pr,tre[node].sr});
        }
    }
    void upd(ll node,ll start,ll end,ll pos,ll val)
    {
        if(start==end)
        {
            v[pos]=val;
            tre[node].sum=tre[node].pr=tre[node].sr=tre[node].maxi=val;
        }
        else
        {
            ll mid=(start+end)/2;
            if(pos>=start&&pos<=mid)
            {
                upd(2*node+1,start,mid,pos,val);
            }
            else
            {
                upd(2*node+2,mid+1,end,pos,val);
            }
             tre[node].sum=tre[2*node+1].sum+tre[2*node+2].sum;
            tre[node].pr=max(tre[2*node+1].sum+tre[2*node+2].pr,tre[2*node+1].pr);
            tre[node].sr=max(tre[2*node+1].sr+tre[2*node+2].sum,tre[2*node+2].sr);
            tre[node].maxi=max({tre[2*node+1].maxi,tre[2*node+2].maxi,tre[2*node+1].sr+tre[2*node+2].pr
            ,tre[node].pr,tre[node].sr});
        }
        
    }
    subaray query(ll node,ll start,ll end,ll l,ll r)
    {
        subaray res;
        res.maxi=res.pr=res.sr=res.sum=INT_MIN;
        if(start>r||l>end)
        {
            return res;
        }
        if(start>=l&&end<=r)
        {
            return tre[node];
        }
        else
        {
            ll mid=(start+end)/2;
            subaray p1=query(2*node+1,start,mid,l,r);
            subaray p2=query(2*node+2,mid+1,end,l,r);
            res.sum=p1.sum+p2.sum;
            res.pr=max(p1.sum+p2.pr,p1.pr);
            res.sr=max(p1.sr+p2.sum,p2.sr);
            res.maxi=max({p1.maxi,p2.maxi,p1.sr+p2.pr
            ,res.pr,res.sr});
            return res;
        }
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>segment::v[i];
    }
    segment::build(0,0,n-1);
    while(q--)
    {
        ll pos,val;
        cin>>pos>>val;
        segment::upd(0,0,n-1,pos-1,val);
        cout<<max(0ll,segment::query(0,0,n-1,0,n-1).maxi)<<endl;
    }
    return 0;
}