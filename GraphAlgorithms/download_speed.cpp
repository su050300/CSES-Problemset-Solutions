#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
#define ll long long int
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
#define vi vector<long long int> 
#define vii vector<vi>
#define vp vector<pair<ll,ll>>
#define vpp vector<pair<ll,pair<ll,ll>>>
#define pb push_back
#define pu push
#define po pop
#define up(v,x) upper_bound(v.begin(),v.end(),x)
#define lo(v,x) lower_bound(v.begin(),v.end(),x)
#define ups(v,x) v.upper_bound(x)
#define los(v,x) v.loer_bound(x)
#define pa pair<long long int ,long long int> 
#define f(a,x,b) for(int a=x;a<b;a++)
#define fr(a,x,b) for(int a=x;a>=b;a--)
#define sort(x) sort(x.begin(),x.end())
#define rev(x) reverse(x.begin(),x.end())
#define sz(a) (int)a.size()
#define mod 1000000007
#define F first
#define S second
#define um unordered_map<ll,ll>
#define ordered_set tree<pa, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update
/* *** dinic algorithm using scaling *** */

struct edge {
    int a, b, f, c;
};

const int inf = 1000 * 1000 * 1000;
const int MAXN = 1050;

int n, m;
vector <edge> e;
int pt[MAXN]; // very important performance trick
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;
int d[MAXN];
int lim;
int s, t;

void add_edge(int a, int b, int c) {                                                                           
    edge ed;

    //keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge 

    ed.a = a; ed.b = b; ed.f = 0; ed.c = c;
    g[a].push_back(e.size());
    e.push_back(ed);

    ed.a = b; ed.b = a; ed.f = c; ed.c = c;
    g[b].push_back(e.size());
    e.push_back(ed);
}

bool bfs() {
    for (int i = s; i <= t; i++)
        d[i] = inf;
    d[s] = 0; 
    q.push(s);
    while (!q.empty() && d[t] == inf) {
        int cur = q.front(); q.pop();
        for (size_t i = 0; i < g[cur].size(); i++) {
            int id = g[cur][i];
            int to = e[id].b;

            //printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);

            if (d[to] == inf && e[id].c - e[id].f >= lim) {
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }
    while (!q.empty()) 
        q.pop();
    return d[t] != inf;
}

bool dfs(int v, int flow) {
    if (flow == 0) 
        return false;
    if (v == t) {
        //cout << v << endl;
        return true;
    }
    for (; pt[v] < g[v].size(); pt[v]++) {
        int id = g[v][pt[v]];
        int to = e[id].b;

        //printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

        if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
            int pushed = dfs(to, flow); 
            if (pushed) {
                e[id].f += flow;
                e[id ^ 1].f -= flow;
                return true;
            }               
        }
    }
    return false;
}

void dinic() {
    for (lim = (1 << 30); lim >= 1;) {
        if (!bfs()) {
            lim >>= 1;
            continue;
        }

        for (int i = s; i <= t; i++) 
            pt[i] = 0;

        int pushed;

        while (pushed = dfs(s, lim)) { 
            flow = flow + lim;
        }

        //cout << flow << endl;
    }
}
/* *** dinic algorithm *** */
// namespace max_flow_graph{
//     struct edge{
//         ll u,v,capacity,flow;
//     };
//     ll n;
//     vector<edge>el;
//     vi g[1001];
//     vi dist(1001),par(1001);
 
//     void add_edge(ll u,ll v,ll w)
//     {
//         g[u].pb(el.size());
//         el.pb({u,v,w,0});
//         g[v].pb(el.size());
//         el.pb({v,u,0,0});
//     }
 
//     int send_one_flow(ll s,ll e)
//     {
//          ll mini=1e9;
//          for(int u=e;u!=s;u=el[par[u]].u)
//          {
//             mini=min(mini,el[par[u]].capacity-el[par[u]].flow);
//          }
 
//          for(int u=e;u!=s;u=el[par[u]].u)
//          {
//             el[par[u]].flow+=mini;
//             el[par[u]^1].flow-=mini;
//          }
//          return mini;
//     }
 
//     bool bfs(ll s,ll e)
//     {
//         dist.assign(n+1,1e9);
//         par.assign(n+1,0);
//         queue<ll>q;
//         q.push(s);
//         dist[s]=0;
//         while(q.size())
//         {
//             int u=q.front();
//             q.pop();
//             if(u==e)
//             {
//                 break;
//             }
//             for(ll idx:g[u])
//             {
//                 if(el[idx].capacity>el[idx].flow&&dist[el[idx].v]>dist[el[idx].u]+1)
//                 {
//                     dist[el[idx].v]=dist[el[idx].u]+1;
//                     par[el[idx].v]=idx;
//                     q.push(el[idx].v);
//                 }
//             }
//         }
//         return dist[e]<1e9;
//     }
 
//     ll dfs(ll s,ll e,ll f=1e9)
//     {
//         if(s==e || f==0)
//         return f;
//         for(ll idx:g[s])
//         {
//             if(dist[el[idx].v]!=dist[s]+1) 
//             continue;
//             if(ll nf=dfs(el[idx].v,e,min(f,el[idx].capacity-el[idx].flow)))
//             {
//                 el[idx].flow+=nf;
//                 el[idx^1].flow-=nf;
//                 return nf;
//             }
//         }
//         return 0;
//     }
    
//     ll dinic(ll s,ll e)
//     {
//         ll mf=0;
//         while(bfs(s,e))
//         {
//             while(ll nf=dfs(s,e))
//             mf+=nf;
//         }
//         return mf;
//     }
// };
void solve(){
   ll n,m;
   cin>>n>>m;
   s=1,t=n;
   f(i,0,m)
   {
       ll u,v,w;
       cin>>u>>v>>w;
       add_edge(u,v,w);       
   }
   dinic();

   cout<<flow<<endl;
}
int main() {
	fast;
	fast_input;
	fast_output;
	// ll t;
	// cin>>t;
	// f(i,0,t)
	// {
        //  cout<<"Case #"<<i+1<<":"<<" ";
	     solve();
	// }
	return 0;
}
