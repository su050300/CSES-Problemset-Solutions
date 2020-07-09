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
            res^=bit[ind];
            ind-=ind&-ind;
        }
        return res;
    }
    void upd(ll ind,ll val)
    {
        while(ind<=n)
        {
           bit[ind]^=val;
           ind+=ind&-ind;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    fenwick::n=n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v[i]=x;
        fenwick::upd(i+1,x);
    }
    for(int i=0;i<q;i++)
    {
            ll a,b;
            cin>>a>>b;
            cout<<(fenwick::get(b)^fenwick::get(a-1))<<endl;  
    }
    return 0;
}