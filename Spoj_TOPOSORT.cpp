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
vector<int> adj[10001];
bool vis[10001];
vector<int> v;
int n, m;
void dfs(int node)
{
	vis[node] = true;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
	v.pb(node);
}
bool helper(int node, vector<bool> &visited, vector<bool> &instack)
{
	visited[node] = true;
	instack[node] = true;
	for (auto child : adj[node])
	{
		if (!visited[child] and helper(child, visited, instack))
			return true;
		if (instack[child])
			return true;
	}
	instack[node] = false;
	return false;
}
bool cycle()
{
	vector<bool> visited(n + 1, false), instack(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			if (helper(i, visited, instack))
				return true;
	}
	return false;
}
int32_t main()
{
	fast();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
	}
	if (cycle() == 1)
		cout << "Sandro fails.\n";
	else
	{
		for (int i = 1; i <= n; i++)
			sort(adj[i].begin(), adj[i].end(), greater<int> ());
		for (int i = n; i >= 1; i--)
			if (!vis[i])
				dfs(i);
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
	}
	return 0;
}