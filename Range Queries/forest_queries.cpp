#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>>v(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='*')
            {
                v[i][j]=1;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
              v[i][j]+=v[i][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            v[i][j]+=v[i-1][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<(v[x2][y2]-v[x1-1][y2]-v[x2][y1-1]+v[x1-1][y1-1])<<endl;
    }
    return 0;
}