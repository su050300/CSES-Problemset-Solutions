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
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pair<ll, ll>>
#define vpp vector<pair<ll, pair<ll, ll>>>
#define pb push_back
#define pu push
#define po pop
#define up(v, x) upper_bound(v.begin(), v.end(), x)
#define lo(v, x) lower_bound(v.begin(), v.end(), x)
#define ups(v, x) v.upper_bound(x)
#define los(v, x) v.loer_bound(x)
#define pa pair<long long int, long long int>
#define f(a, x, b) for (int a = x; a < b; a++)
#define fr(a, x, b) for (int a = x; a >= b; a--)
#define EACH(a, x) for (auto a : x)
#define sort(x) sort(x.begin(), x.end())
#define rev(x) reverse(x.begin(), x.end())
#define sz(a) (int)a.size()
#define mod 1000000007
#define F first
#define S second
#define endl "\n"
#define um unordered_map<ll, ll>
#define ordered_set tree < pa, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update

vector<string> vec_splitter(string s)
{
	s += ',';
	vector<string> res;
	while (!s.empty())
	{
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
	vector<string> __attribute__((unused)) args,
	__attribute__((unused)) int idx,
	__attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
	if (idx > 0)
		cerr << ", ";
	else
		cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss;
	ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
ll x;
set<ll> g[400001], gt[400001];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v)
{
	used[v] = true;
	for (int u : g[v])
	{
		if (!used[u])
			dfs1(u);
	}
	order.push_back(v);
}

void dfs2(int v, int cl)
{
	comp[v] = cl;
	for (int u : gt[v])
	{
		if (comp[u] == -1)
			dfs2(u, cl);
	}
}

bool solve_2SAT()
{
	used.assign(x, false);
	for (int i = 0; i < x; ++i)
	{
		if (!used[i])
			dfs1(i);
	}

	comp.assign(x, -1);
	for (int i = 0, j = 0; i < x; ++i)
	{
		int v = order[x - i - 1];
		if (comp[v] == -1)
			dfs2(v, j++);
	}

	assignment.assign(x / 2, false);
	for (int i = 0; i < x; i += 2)
	{
		if (comp[i] == comp[i + 1])
			return false;
		assignment[i / 2] = comp[i] > comp[i + 1];
	}
	return true;
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	x = 2 * m;
	f(i, 0, n)
	{
		ll u, v;
		char s1, s2;
		cin >> s1 >> u >> s2 >> v;
		u--, v--;
		u *= 2;
		v *= 2;
		// either u or v or both
		if (s1 == '-' && s2 == '-')
		{
			g[u + 1].insert(v);
			g[v + 1].insert(u);
			gt[v].insert(u + 1);
			gt[u].insert(v + 1);
		}
		else if (s1 == '-' && s2 == '+')
		{
			g[u + 1].insert(v + 1);
			g[v].insert(u);
			gt[v + 1].insert(u + 1);
			gt[u].insert(v);
		}
		else if (s1 == '+' && s2 == '-')
		{
			g[u].insert(v);
			g[v + 1].insert(u + 1);
			gt[v].insert(u);
			gt[u + 1].insert(v + 1);
		}
		else if (s1 == '+' && s2 == '+')
		{
			g[u].insert(v + 1);
			g[v].insert(u + 1);
			gt[v + 1].insert(u);
			gt[u + 1].insert(v);
		}
	}
	if (solve_2SAT())
	{
		f(i, 0, m)
		{
			cout << (assignment[i] == 1 ? '-' : '+') << " ";
		}
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}
}
int main()
{
	fast;
	fast_input;
	fast_output;
	// ll t;
	// cin >> t;
	// f(i, 0, t)
	// {
	//  cout<<"Case #"<<i+1<<":"<<" ";
	solve();
	// }
	return 0;
}