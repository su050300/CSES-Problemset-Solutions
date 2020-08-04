#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    int startx=0,starty=0,endx=0,endy=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='A')
            {
                startx=i,starty=j;
            }
            if(v[i][j]=='B')
            {
                endx=i,endy=j;
            }
        }
    }
    vector<vector<int>>visited(n,vector<int>(m));
    vector<vector<char>>path(n,vector<char>(m));
    vector<pair<int,int>>pos={{0,1},{1,0},{0,-1},{-1,0}};
    vector<char>typ={'R','D','L','U'};
    queue<pair<int,int>>q;
    q.push({startx,starty});
    visited[startx][starty]=1;
    path[startx][starty]='F';
    bool found=false;
    while(!q.empty())
    {
        pair<int,int> d=q.front();
        q.pop();
        int fl=0;
        for(int i=0;i<4;i++)
        {
            int x=d.first+pos[i].first;
            int y=d.second+pos[i].second;
            if(x>=0&&x<n&&y>=0&&y<m&&!visited[x][y])
            {
                if(v[x][y]=='B')
                {
                    fl=1;
                    visited[x][y]=1;
                    path[x][y]=typ[i];
                    break;
                }
                else if(v[x][y]=='.')
                {
                    visited[x][y]=1;
                    path[x][y]=typ[i];
                    q.push({x,y});
                }
            }
        }
        if(fl)
        {
         found=true;
         break;
        }
    }
    if(found)
    {
        cout<<"YES"<<endl;
        vector<char>res;
        // cout<<startx<<" "<<starty<<endl;
        while(path[endx][endy]!='F')
        {
            // cout<<endx<<" "<<endy<<endl;
            if(path[endx][endy]=='L')
            {
                res.push_back('L');
                endy+=1;
            }
            else if(path[endx][endy]=='R')
            {
                res.push_back('R');
                endy-=1;
            }
            else if(path[endx][endy]=='U')
            {
                res.push_back('U');
                endx+=1;
            }
            else
            {
                res.push_back('D');
                endx-=1;
            }
        }
        reverse(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(auto d:res)
        {
            cout<<d;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}