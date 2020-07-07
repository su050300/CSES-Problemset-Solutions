#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace fenwick
{
    ll bit[2000001],n;
    ll get(ll ind)
    {
        ll res=0;
        while(ind>=1)
        {
            res+=bit[ind];
            ind-=ind&-ind;
        }
        return res;
    }
    void upd(ll ind,ll val)
    {
        while(ind<=n)
        {
           bit[ind]+=val;
           ind+=ind&-ind;
        }
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    fenwick::n=n+1;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<q;i++)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll a,b,val;
            cin>>a>>b>>val;
            fenwick::upd(a,val);
            fenwick::upd(b+1,-val);
        }
        else
        {
            ll pos;
            cin>>pos;
            cout<<(v[pos-1]+fenwick::get(pos))<<endl;
        }     
    }
    return 0;
}