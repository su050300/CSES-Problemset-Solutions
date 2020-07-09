#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace fenwick
{
    ll bit[1000001],n;
    void upd(ll ind,ll val)
    {
        while(ind<=n)
        {
            bit[ind]+=val;
            ind+=ind&-ind;
        }
    }
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
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    fenwick::n=n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        fenwick::upd(i+1,1);
    }
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        ll l=1,r=n;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            ll ge=fenwick::get(mid);
            if(ge>=x)
            {
               r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<v[r]<<" ";
        fenwick::upd(r+1,-1);
    }
    return 0;
}