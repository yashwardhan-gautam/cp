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
// zero based indexing
int n, m;
int source;
vector<vector<int> > adj;
vector<int> dis, parent;
vector<bool> vis;
void bfs(int source)
{
	vis.resize(n, false);
	queue<int> q;

	vis[source] = true;
	q.push(source);
	parent[source] = -1;
	dis[source] = 0;
	while (!q.empty())
	{
		int curr = q.front();	q.pop();
		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				vis[child] = true;
				q.push(child);
				parent[child] = curr;
				dis[child] = dis[curr] + 1;
			}
		}
	}
	for (int i = 0; i < dis.size(); i++)
	{
		// edge from parent to curr node, shortest distance of current node from source
		cout << parent[i] << "-->" << i << " " << dis[i] << endl;
	}
}
void bfs_path(int dest)
{
	// no path exist
	if (!vis[dest])
		return ;
	vector<int> path;
	int u = dest;
	while (u != -1)
	{
		path.insert(path.begin(), u);
		u = parent[u];
	}
	for (auto node : path)
		cout << node << " ";
	cout << endl;
}
int32_t main()
{
	fast();
	// number of nodes and number of edges
	cin >> n >> m;
	adj.resize(n), dis.resize(n), parent.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
	}
	cin >> source;
	int dest;	cin >> dest;
	bfs(source);
	bfs_path(dest);
	return 0;
}