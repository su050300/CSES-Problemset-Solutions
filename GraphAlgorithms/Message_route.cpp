#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>visited(n);
    vector<int>dist(n);
    vector<int>path(n,-1);
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty())
    {
        int d=q.front();
        q.pop();
        for(int ge:g[d])
        {
            if(!visited[ge])
            {
                path[ge]=d;
                dist[ge]=dist[d]+1;
                visited[ge]=1;
                q.push(ge);
            }
            else
            {
                if(dist[d]+1 < dist[ge])
                {
                    dist[ge]=dist[d]+1;
                    path[ge]=d;
                }
            }
        }
    }
    if(path[n-1]!=-1)
    {
        // cout<<"YES"<<endl;
        vector<int>res;
        int curr=n-1;
        res.push_back(n-1);
        while(path[curr]!=-1)
        {
            res.push_back(path[curr]);
            curr=path[curr];
        }
        cout<<res.size()<<endl;
        reverse(res.begin(),res.end());
        for(int d:res)
        {
            cout<<d+1<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    return 0;
}