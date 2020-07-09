#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    ll pref[n+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        pref[i+1]=v[i]+pref[i];
    }
    for(int i=0;i<q;i++)
    {
        ll x,y;
        cin>>x>>y;
        cout<<pref[y]-pref[x-1]<<endl;
    }
    return 0;
}