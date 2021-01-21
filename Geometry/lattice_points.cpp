#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct P
{
    ll x, y;
    void read()
    {
        cin >> x >> y;
    }
    P operator-(P b)
    {
        return P{x - b.x, y - b.y};
    }
    P operator+(P b)
    {
        return P{x + b.x, y + b.y};
    }
    ll operator*(P b)
    {
        return b.y * x - b.x * y;
    }
};
void solve()
{
    ll n;
    cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].read();
    }
    ll area = 0;
    for (int i = 0; i < n; i++)
    {
        area += v[i] * v[(i + 1) % n];
    }
    ll boundary = 0;
    for (int i = 0; i < n; i++)
    {
        P p = v[i] - v[(i + 1) % n];
        boundary += __gcd(abs(p.x), abs(p.y));
    }
    ll interior = abs(area) - boundary + 2;
    interior /= 2;
    cout << interior << " " << boundary << endl;
}
int main()
{
    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}