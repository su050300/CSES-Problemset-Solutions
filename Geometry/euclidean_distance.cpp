#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct pt
{
    int x, y, id;
};
 
struct cmp_x
{
    bool operator()(const pt &a, const pt &b) const
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};
 
struct cmp_y
{
    bool operator()(const pt &a, const pt &b) const
    {
        return a.y < b.y;
    }
};
 
int n;
vector<pt> a;
long long int mindist;
pair<int, int> best_pair;
 
void upd_ans(const pt &a, const pt &b)
{
    ll dist = ((ll)(a.x - b.x) * (ll)(a.x - b.x) + (ll)(a.y - b.y) * (ll)(a.y - b.y));
    if (dist < mindist)
    {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}
vector<pt> t;
 
void rec(int l, int r)
{
    if (r - l <= 3)
    {
        for (int i = l; i < r; ++i)
        {
            for (int j = i + 1; j < r; ++j)
            {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }
 
    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);
 
    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);
 
    int tsz = 0;
    for (int i = l; i < r; ++i)
    {
        if (abs(a[i].x - midx) < mindist)
        {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}
 
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        struct pt p;
        cin >> p.x >> p.y;
        a.push_back(p);
    }
    t.resize(n);
    sort(a.begin(), a.end(), cmp_x());
    mindist = 1e18;
    rec(0, n);
    cout << mindist;
}
int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}