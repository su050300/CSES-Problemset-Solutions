#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    queue<pair<ll,ll>>q;
    vector<vector<ll>>visited(n,vector<ll>(m));
    vector<pair<ll,ll>>pos={{0,1},{1,0},{-1,0},{0,-1}};
    ll co=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(v[i][j]=='.'&&!visited[i][j])
           {
           q.push({i,j});
           visited[i][j]=1;
           while(!q.empty())
           {
              pair<ll,ll>d=q.front();
              q.pop();
              for(int l=0;l<4;l++)
              {
                ll x=d.first+pos[l].first;
                ll y=d.second+pos[l].second;
                if(x>=0&&x<n&&y>=0&&y<m&&!visited[x][y]&&v[x][y]=='.')
                {
                    q.push({x,y});
                    visited[x][y]=1;
                }
              }
            }
                 co++; 
           }
        }
    }
    cout<<co<<endl;
    return 0;
}
