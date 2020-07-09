#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
    ll n,q;
    cin>>n>>q;
    ordered_set s;
    ll t=0;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v[i]=x;
        t++;
        s.insert({x,t});
    }
    for(int i=0;i<q;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='?')
        {
            ll a,b;
            cin>>a>>b;
            ll dist=s.order_of_key({b+1,0});
            ll dis=s.order_of_key({a,0});
            cout<<dist-dis<<endl;
        }
        else
        {
            ll pos,val;
            cin>>pos>>val;
            auto it=(s.lower_bound({v[pos-1],0}));
            v[pos-1]=val;
            s.insert({val,(*(it)).second});
            s.erase(it);
        }
        
    }
    return 0;
}