#include<bits/stdc++.h>
using namespace std;
#define ll long long int
namespace merge_sort_tree
{
    vector<ll>tre[1000001];
    vector<ll>v(1000001);
    vector<ll> merge(vector<ll>&a,vector<ll>&b)
    {
        ll n=a.size(),m=b.size(),i=0,j=0;
        vector<ll>res;
        while(i<n&&j<m)
        {
           if(a[i]<=b[j])
           {
               res.push_back(a[i]);
               i++;
           }
           else
           {
               res.push_back(b[j]);
               j++;   
           }
        }
        while(i<n)
        {
            res.push_back(a[i]);
            i++;
        }
        while(j<m)
        {
            res.push_back(b[j]);
            j++;
        }
        return res;
    }
    void build(ll node,ll l,ll r)
    {
        if(l==r)
        {
            tre[node].push_back(v[l]);
        }
        else
        {
           ll mid=(l+r)/2;
           build(2*node+1,l,mid);
           build(2*node+2,mid+1,r);
           tre[node]=merge(tre[2*node+1],tre[2*node+2]);   
        }
    }
    ll query(ll node,ll start,ll end,ll l,ll r)
    {
        if(start>r||l>end)
        {
            return 0;
        }
        if(start>=l&&end<=r)
        {
            auto it=upper_bound(tre[node].begin(),tre[node].end(),r);
            return tre[node].size()-(it-tre[node].begin());
        }
        ll mid=(start+end)/2;
        ll p1=query(2*node+1,start,mid,l,r);
        ll p2=query(2*node+2,mid+1,end,l,r);
        return p1+p2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<ll,ll>mp;
    map<ll,ll>seen;
    vector<ll>v1(n);
    for(int i=n-1;i>=0;i--)
    {
       if(!mp[v[i]])
       {
           mp[v[i]]=1e10;
       }
       else
       {
           mp[v[i]]=seen[v[i]];
       }
       seen[v[i]]=i;
       v1[i]=mp[v[i]];
    }
    for(int i=0;i<n;i++)
    {
        merge_sort_tree::v[i]=v1[i];
    }
    merge_sort_tree::build(0,0,n-1);
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        cout<<merge_sort_tree::query(0,0,n-1,a,b)<<"\n";
    }
    return 0;
}

                                             
//time complexicity of above method is O(n(logn)^2),space complexicity O(nlogn)

//the above problem can be solved using mo's algorithm in O((n+q)*(sqrt(n))*f) time and O(n) space below is the implementation

//the mo's algorithm method works only when queries are known beforehand(offline) but above method works in both cases(online/offline)

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// ll maxi=555;
// ll freq[200001];
// vector<ll>v(200001);
// struct query
// {
//     ll l,r,ind;
// };
// vector<query>queries;
// ll comp(query &a,query &b)
// {
//     ll b1=a.l/maxi;
//     ll b2=b.l/maxi;
//     if(b1==b2)
//     {
//         return a.r<b.r;
//     }
//     return b1<b2;
// }
// ll an;
// void add(ll pos)
// {
//    if(!freq[v[pos]])
//     an++;
//    freq[v[pos]]++;
// }
// void remove(ll pos)
// {
//    freq[v[pos]]--;
//    if(freq[v[pos]]==0)
//    {
//      an--;
//    }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll n,q;
//     cin>>n>>q;
//     an=0;
//     map<ll,ll>compress;
//     ll tempo=1;
//     for(int i=0;i<n;i++)
//     {
//         cin>>v[i];
//         if(compress.find(v[i])==compress.end())
//         {
//            compress[v[i]]=tempo;
//            v[i]=tempo;
//            tempo++;
//         }
//         else
//         {
//             v[i]=compress[v[i]];
//         }
//     }
//     vector<ll>ans(q);
//     for(int i=0;i<q;i++)
//     {
//         ll l,r;
//         cin>>l>>r;
//         l--,r--;
//         query te;
//         te.l=l,te.r=r,te.ind=i;
//         queries.push_back(te);
//     }
//     sort(queries.begin(),queries.end(),comp);
//     ll ml=0,mr=-1;
//     for(int i=0;i<q;i++)
//     {
//         ll l=queries[i].l;
//         ll r=queries[i].r;
//         ll ind=queries[i].ind;
//         // cout<<l<<" "<<r<<" "<<ind<<endl;
//         while(mr<r)
//         {
//             mr++;
//             add(mr);
//         }
//         while(ml>l)
//         {
//             ml--;
//             add(ml);
//         }
//         while(mr>r)
//         {
//             remove(mr);
//             mr--;
//         }
//         while(ml<l)
//         {
//             remove(ml);
//             ml++;
//         }
//         ans[ind]=an;
//     }
//     for(int i=0;i<q;i++)
//     {
//         cout<<ans[i]<<"\n";
//     }
//     return 0;
// }
