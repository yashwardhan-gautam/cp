// https://www.spoj.com/problems/HOLI/
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
vector<vector<pii> > adj;
int res = 0;
int dfs(int node, int parent)
{
	int ans = 1;
	for (auto child : adj[node])
	{
		if (child.fi == parent)
			continue;
		int x = dfs(child.fi, node);
		res += 2 * min(x, n - x) * child.se;
		ans += x;
	}
	return ans;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	int tc = 1;
	while (test--)
	{
		cin >> n;
		adj.resize(n + 1);
		for (int i = 0; i < n - 1; i++)
		{
			int u, v, w;	cin >> u >> v >> w;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
		}
		res = 0;
		dfs(1, -1);
		cout << "Case #" << tc << ": " << res << endl;
		tc++;
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
	return 0;
}