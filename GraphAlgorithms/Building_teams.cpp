#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    int visited[n]={0};
    int colour[n]={0};
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isBipartite=true;
    for(int i=0;i<n;i++)
    {
    if(!visited[i])
    {
    queue<int>q;
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        int d=q.front();
        q.pop();
        for(int ge:g[d])
        {
            if(!visited[ge])
            {
                colour[ge]=colour[d]^1;
                visited[ge]=1;
                q.push(ge);
            }
            else
            {
                if(colour[ge]==colour[d])
                {
                    isBipartite=false;
                }
            }
        }
    }
    }
    }
    if(isBipartite)
    {
        for(int i=0;i<n;i++)
        {
            cout<<colour[i]+1<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    
    return 0;
}