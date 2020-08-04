#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    vector<vector<int>>poss(n,vector<int>(m,-1));
    queue<pair<int,int>>q;
    int xi,yi;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='M')
            {
                q.push({i,j});
                poss[i][j]=0;
            }
            if(v[i][j]=='A')
            {
              xi=i,yi=j;
            }
        }
    }
    vector<vector<int>>visited(n,vector<int>(m));
    vector<pair<int,int>>pos={{1,0},{0,1},{-1,0},{0,-1}};
    vector<char>pat={'D','R','U','L'};
    while(!q.empty())
    {
        pair<int,int>d=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=pos[i].first+d.first;
            int y=pos[i].second+d.second;
            if(x>=0&&x<n&&y>=0&&y<m&&!visited[x][y]&&v[x][y]=='.')
            {
                visited[x][y]=1;
                q.push({x,y});
                poss[x][y]=poss[d.first][d.second]+1;
            }
            // else if(x>=0&&x<n&&y>=0&&y<m&&v[x][y]=='.')
            // {
            //     poss[x][y]=min(poss[x][y],poss[d.first][d.second]);
            // }
        }
    }
    q.push({xi,yi});
    vector<vector<int>>vis(n,vector<int>(m));
    vector<vector<int>>posss(n,vector<int>(m,-1));
    vector<vector<char>>path(n,vector<char>(m));
    posss[xi][yi]=0;
    vis[xi][yi]=1;
    if(poss[xi][yi]!=-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(!q.empty())
    {
        pair<int,int>d=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=d.first+pos[i].first;
            int y=d.second+pos[i].second;
            if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&v[x][y]=='.')
            {
                vis[x][y]=1;
               if(poss[x][y]!=-1&&poss[x][y]<=posss[d.first][d.second]+1)
               {
                  continue;
               }      
               posss[x][y]=posss[d.first][d.second]+1;
               q.push({x,y});
               path[x][y]=pat[i];
            }
        }
    }
    int selx=-1,sely=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
        //    cout<<posss[i][j]<<" ";
           if(i==0||j==0||i==n-1||j==m-1)
           {
               if((v[i][j]=='.'||v[i][j]=='A')&&posss[i][j]!=-1)
               {
                  selx=i,sely=j;
                  break;
               }
           }
        }
        // cout<<endl;
    }
    if(selx==-1&&sely==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        vector<char>res;
        path[xi][yi]='F';
        while(path[selx][sely]!='F')
        {
        //    cout<<selx<<" "<<sely<<endl;
           res.push_back(path[selx][sely]);
           if(path[selx][sely]=='L')
           {
               sely+=1;
           }
           else if(path[selx][sely]=='R')
           {
               sely-=1;
           }
           else if(path[selx][sely]=='U')
           {
               selx+=1;
           }
           else
           {
               selx-=1;
           }
        }
        reverse(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(char d:res)
        {
            cout<<d;
        }
    }
    
    return 0;
}