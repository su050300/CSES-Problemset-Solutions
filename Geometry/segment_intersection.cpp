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
ll check(P p1, P p2, P p3, P p4)
{
    p2 = p2 - p1;
    p3 = p3 - p1;
    p4 = p4 - p1;
    ll sign = p2 * p3;
    ll sign1 = p2 * p4;
    if ((sign > 0 && sign1 > 0) || (sign < 0 && sign1 < 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
ll chk(P p1,P p2,P p3,P p4)
{
    if((max(p1.x,p2.x)<min(p3.x,p4.x))||(max(p1.y,p2.y)<min(p3.y,p4.y)))
    {
        return 0;
    }
    return 1;
}
void solve()
{
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    // handle cases when segments are parralel 
    if((p2-p1)*(p4-p3)==0)
    {
        if(!check(p1,p2,p3,p4))
        {
            cout<<"NO"<<endl;
            return;
        }
        // handle collinear cases 
        if(!chk(p1,p2,p3,p4)||!chk(p3,p4,p1,p2))
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        return;
    }
    if (check(p1, p2, p3, p4) && check(p3, p4, p1, p2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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