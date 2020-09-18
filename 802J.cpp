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
int n;
int ans;

vector<pair<int, int> > adj[101];
void dfs(int node, int parent, int cost)
{
	ans = max(ans, cost);
	for (int i = 0; i < adj[node].size(); i++)
	{
		if (parent != adj[node][i].fi)
			dfs(adj[node][i].fi, node, cost + adj[node][i].se);
	}
}
int32_t main()
{
	fast();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u, v, w;	cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	dfs(0, -1, 0);
	cout << ans << endl;
	return 0;
}