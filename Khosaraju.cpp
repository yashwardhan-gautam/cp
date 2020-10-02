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
//Finding the strongly connected components
int n, m;
vector<vector<int> > adj, tadj;
vector<bool> vis;
vector<int> v;
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
	cin >> n >> m;
	adj.resize(n + 1), tadj.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		tadj[v].pb(u);
	}
	vis.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i);
	}
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
	for (int i = 0; i < res.size(); i++)
	{
		cout << "component " << i + 1 << ":\n";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
Sample input :
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4
*/
/*
Sample output:
component 1:
1 3 2
component 2:
4 6 5
*/
