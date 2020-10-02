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
int n, k;
vector<vector<int> > adj;
vector<int> res;
vector<bool> vis, instack;
void dfs(int node)
{
	vis[node] = true;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
	res.pb(node);
}
bool cycle(int node)
{
	instack[node] = true;
	vis[node] = true;
	for (auto child : adj[node])
	{
		if (!vis[child] and cycle(child))
			return true;
		if (instack[child])
			return true;
	}
	instack[node] = false;
	return false;
}
int32_t main()
{
	fast();
	cin >> n >> k;
	adj.resize(n + 1);
	vector<int> v(k);
	for (int i = 0; i < k; i++)	cin >> v[i];
	for (int u = 1; u <= n; u++)
	{
		int t;	cin >> t;
		for (int j = 0; j < t; j++)
		{
			int v;	cin >> v;
			adj[u].pb(v);
		}
	}
	vis.resize(n + 1, false);
	instack.resize(n + 1, false);
	// doesn't matter if there's a cycle until,any of the main courses is a part of some cycle.
	for (int i = 0; i < v.size(); i++)
	{
		if (!vis[v[i]] and cycle(v[i]))
		{
			cout << "-1\n";
			return 0;
		}
	}
	fill(vis.begin(), vis.end(), false);
	for (int i = 0; i < v.size(); i++)
	{
		if (!vis[v[i]])
			dfs(v[i]);
	}
	cout << res.size() << "\n";
	for (auto it : res)
		cout << it << " ";
	cout << endl;
	return 0;
}