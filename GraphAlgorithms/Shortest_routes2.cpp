#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>dist(n,vector<ll>(n,10000000000000000));
    for(int i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++)
    {
       ll x,y,w;
       cin>>x>>y>>w;
       x--,y--;
       dist[x][y]=min(dist[x][y],w);
       dist[y][x]=min(dist[y][x],w);
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j] < dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        if(dist[x][y]!=10000000000000000)
        cout<<dist[x][y]<<"\n";
        else
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}