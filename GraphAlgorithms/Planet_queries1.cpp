#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>>lift(200001,vector<ll>(31,-1));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        x--;
        lift[i][0]=x;
    }
    for(int i=1;i<31;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll curr=lift[j][i-1];
            if(curr!=-1)
            {
                lift[j][i]=lift[curr][i-1];
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        if(y==0)
        {
            cout<<x+1<<"\n";
            continue;
        }
        for(int j=30;j>=0;j--)
        {
            if(y&(1<<j))
            {
                x=lift[x][j];
            }
        }
        cout<<x+1<<"\n";
    }
    return 0;
}