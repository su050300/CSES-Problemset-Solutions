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
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p3 = p3 - p1;
    p2 = p2 - p1;
    ll res = p2 * p3;
    if (res > 0)
    {
        cout << "LEFT" << endl;
    }
    else if (res < 0)
    {
        cout << "RIGHT" << endl;
    }
    else
    {
        cout << "TOUCH" << endl;
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}