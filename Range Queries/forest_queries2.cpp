#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace fenwick
{
    ll bit[1001][1001],n;
    void upd(ll ind,ll ind1,ll val)
    {
        while(ind<=n)
        {
            ll has=ind1;
            while(has<=n)
            {
                bit[ind][has]+=val;
                has+=has&-has;
            }
            ind+=ind&-ind;
        }
    }
    ll get(ll ind,ll pos)
    {
        ll res=0;
        while(ind>=1)
        {
            ll has=pos;
            while(has>=1)
            {
                res+=bit[ind][has];
                has-=has&-has;
            }
            ind-=ind&-ind;
        }
        return res;
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<vector<char>>v(n,vector<char>(n));
    fenwick::n=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<ll>>has(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(v[i-1][j-1]=='*')
           {
              fenwick::upd(i,j,1);
           }
        }
    }
    for(int i=0;i<q;i++)
    {
        ll t;
        cin>>t;
        if(t==2)
        {
           ll x1,y1,x2,y2;
           cin>>x1>>y1>>x2>>y2;
           ll ans=fenwick::get(x2,y2)+fenwick::get(x1-1,y1-1)-fenwick::get(x1-1,y2)-fenwick::get(x2,y1-1);
           cout<<ans<<endl;
        }
        else
        {
           ll x,y;
           cin>>x>>y;
           ll ge=0;
           if(v[x-1][y-1]=='.')
           {
               ge++;
               v[x-1][y-1]='*';
           }   
           else
           {
               ge--;
               v[x-1][y-1]='.';
           }
           fenwick::upd(x,y,ge);
        }
    }
    return 0;
}

