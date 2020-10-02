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
vector<int> cost;
vector<vector<int> > adj, tadj;
vector<int> v;
vector<bool> vis;
void dfs(int node)
{
	vis[node] = true;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
	v.pb(node);
}
void dfs2(int node, vector<int> &temp)
{
	vis[node] = true;
	temp.pb(node);
	for (auto child : tadj[node])
		if (!vis[child])
			dfs2(child, temp);
}
int32_t main()
{
	fast();
	cin >> n;
	adj.resize(n), tadj.resize(n), cost.resize(n);
	for (int i = 0; i < n; i++)	cin >> cost[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		tadj[v].pb(u);
	}
	vis.resize(n, false);
	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);
	fill(vis.begin(), vis.end(), false);
	vector<vector<int> > res;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (!vis[v[i]])
		{
			vector<int> temp;
			dfs2(v[i], temp);
			res.pb(temp);
		}
	}
	int sum = 0, prod = 1;
	for (int i = 0; i < res.size(); i++)
	{
		int temp_sum = inf, count = 0;
		for (int j = 0; j < res[i].size(); j++)
		{
			if (cost[res[i][j]] < temp_sum)
				temp_sum = cost[res[i][j]];
		}
		for (int j = 0; j < res[i].size(); j++)
		{
			if (cost[res[i][j]] == temp_sum)
				count++;
		}
		sum += temp_sum;
		prod = (prod * (count % mod)) % mod;
		prod %= mod;
	}
	cout << sum << " " << prod << "\n";
	return 0;
}