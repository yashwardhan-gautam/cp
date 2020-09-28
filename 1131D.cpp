#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n, m;
vector<int> parent;
vector<int> ra;
vector<pii> edges;
vector<vector<int> > adj;
vector<bool> vis;
vector<int> depth;
vector<int> instack;
int get_parent(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = get_parent(parent[a]);
}
void join(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a != b)
	{
		if (ra[b] > ra[a])
			swap(a, b);
		parent[b] = a;
		if (ra[a] == ra[b])
			ra[a]++;
	}
}
bool cycle_rec(int node)
{
	vis[node] = true;
	instack[node] = true;
	for (auto child : adj[node])
	{
		if (!vis[child] and cycle_rec(child))
			return true;
		if (instack[child])
			return true;
	}
	instack[node] = false;
	return false;
}
bool cycle_exist()
{
	for (int i = 0; i < n + m; i++)
		if (!vis[get_parent(i)] and cycle_rec(i))
			return true;
	return false;
}
void find_depth(int node)
{
	if (depth[node] != -1)
		return ;
	vis[node] = true;
	int d = 0;
	for (auto child : adj[node])
	{
		find_depth(child);
		d = max(d, depth[child]);
	}
	depth[node] = d + 1;
	vis[node] = false;
}
int32_t main()
{
	fast();
	cin >> n >> m;
	parent.resize(n + m);
	ra.resize(n + m);
	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
		ra[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;    cin >> ch;
			if (ch == '=')
				join(i, n + j);
			else if (ch == '>')
				edges.pb({i, n + j});
			else
				edges.pb({n + j, i});
		}
	}
	adj.resize(n + m), vis.resize(n + m, false), instack.resize(n + m, false), depth.resize(n + m, -1);
	// make the graph just considering the super parents
	for (auto e : edges)
		adj[get_parent(e.fi)].pb(get_parent(e.se));
	if (cycle_exist())
	{
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < n + m; i++)
		vis[i] = false;
	for (int i = 0; i < n + m; i++)
		if (!vis[i])
			find_depth(i);
	cout << "Yes\n";
	for (int i = 0; i < n; i++)
		cout << depth[get_parent(i)] << " ";
	cout << endl;
	for (int j = 0; j < m; j++)
		cout << depth[get_parent(n + j)] << " ";
	cout << endl;
	return 0;
}