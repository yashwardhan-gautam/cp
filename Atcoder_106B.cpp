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
int n, m;
vector<vector<int> > adj;
vector<int> a;
vector<int> b;
vector<bool> vis;
int suma, sumb;
void dfs(int node)
{
	vis[node] = true;
	suma += a[node];
	sumb += b[node];
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
}
bool solve()
{
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			suma = 0, sumb = 0;
			dfs(i);
			//cout << suma << " " << sumb << endl;
			if (suma != sumb)
				return false;
		}
	}
	return true;
}
int32_t main()
{
	fast();
	cin >> n >> m;
	adj.resize(n + 1);
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int j = 0; j < n; j++)	cin >> b[j];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vis.resize(n + 1, false);
	if (solve())
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}