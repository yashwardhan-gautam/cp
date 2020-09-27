// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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

int n, p;
vector<vector<int> > adj;
vector<bool> vis;
void dfs(int node, int &c)
{
	vis[node] = true;
	c++;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child, c);
}
int32_t main()
{
	fast();
	cin >> n >> p;
	adj.resize(n);
	for (int i = 0; i < p; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vis.resize(n, false);
	// anser will be C(N,2) - ways in which we can select two astrounots from same country C(K,2)
	int total_ways = (n * (n - 1)) >> 1;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			int c = 0;
			dfs(i, c);
			//cout << c << "\n";
			total_ways -= (c * (c - 1)) >> 1;
		}
	}
	cout << total_ways << endl;
	return 0;
}