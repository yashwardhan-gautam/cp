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
int dfs(int node, int parent, vector<vector<pii> > &adj, int &res, int n)
{
	int ans = 1;
	for (auto child : adj[node])
	{
		if (child.fi == parent)
			continue;
		int nodes = dfs(child.fi, node, adj, res, n);
		res += (nodes) * (n - nodes) * child.se;
		ans += nodes;
	}
	return ans;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int n;	cin >> n;
		vector<vector<pii> > adj;
		adj.resize(n + 1);
		int res = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int u, v, w;	cin >> u >> v >> w;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
		}
		dfs(1, -1, adj, res, n);
		cout << res << endl;
	}
	return 0;
}