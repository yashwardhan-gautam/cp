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
vector<pair<pair<int, int>, bool> > adj[110];
int cost = 0;
vector<bool> vis(110, 0);
void dfs(int x)
{
	vis[x] = true;
	for (auto child : adj[x])
	{
		// adj[1] will contain at 2 elements adj[1][0] and adj[1][1]
		// both of them are of type pair<pair<int,int>,bool>
		// the back edge to one will be from the second element of these two, which is at index 1, i.e. adj[1][1]
		// because the first one will be first iterated during the first iteration of DFS
		if (!vis[child.fi.fi] or (x == adj[1][1].fi.fi and child.fi.fi == 1))
		{
			dfs(child.fi.fi);
			cost += child.fi.se * child.se;
		}
	}
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	int sum_weights = 0;
	for (int i = 0; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		sum_weights += w;
		adj[u].pb({{v, w}, 1});
		adj[v].pb({{u, w}, 0});
	}
	dfs(1);
	cout << min(cost, sum_weights - cost) << endl;
	return 0;
}