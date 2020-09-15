// https://codeforces.com/problemset/problem/1131/D
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
#define endl		 	      "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector<pair<int, int> > edges;
vector<int> adj[3004];
bool cycle = false;
// DSU with elements 0,1,2....n-1
class dsu
{
public:
	vector<int> parent, rank;
	int total_components;
	dsu(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		total_components = n;
	}
	int get(int a)
	{
		if (a == parent[a])
			return a;
		return parent[a] = get(parent[a]);
	}
	void join(int a, int b)
	{
		a = get(a);
		b = get(b);
		if (a != b)
		{
			if (rank[b] > rank[a])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				rank[a]++;
			total_components--;
		}
	}
};
void find_depth(int node, unordered_map<int, bool> &vis, vector<int> &depth)
{
	if (depth[node] != -1)
		return ;
	if (cycle)
		return ;
	if (vis[node])
	{
		cycle = true;
		return ;
	}
	vis[node] = true;
	int d = 0;
	for (auto child : adj[node])
	{
		find_depth(child, vis, depth);
		d = max(d, depth[child]);
	}
	depth[node] = d + 1;
	vis[node] = false;
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	dsu d(n + m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;	cin >> ch;
			if (ch == '=')
				d.join(i, j + n);
			else if (ch == '>')
				edges.pb(mp(i, n + j));
			else
				edges.pb(mp(n + j, i));
		}
	}
	for (auto e : edges)
		adj[d.get(e.fi)].pb(d.get(e.se));
	vector<int> depth(n + m, -1);
	unordered_map<int, bool> vis;
	for (int i = 0; i < n + m; i++)
	{
		if (!vis[d.get(i)]) {
			find_depth(i, vis, depth);
		}
	}
	if (cycle)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << depth[d.get(i)] << " ";	cout << endl;
		for (int j = 0; j < m; j++)
			cout << depth[d.get(n + j)] << " ";
		cout << endl;
	}
	return 0;
}