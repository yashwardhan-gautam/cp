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
// Topological Sorting in a DAG using BFS and DFS
template<typename T>
class Graph
{
	unordered_map<T, list<T> > adj;
	void topological_sort_dfs_helper(T node, unordered_map<T, bool> &vis, list<T> &l)
	{
		vis[node] = true;
		for (auto child : adj[node])
		{
			if (!vis[child])
				topological_sort_dfs_helper(child, vis, l);
		}
		l.push_front(node);
	}
public:
	void addEdge(T u, T v, bool bidir = false)
	{
		adj[u].pb(v);
		if (bidir)
			adj[v].pb(u);
	}
	void topological_sort_dfs()
	{
		unordered_map<T, bool> vis;
		list<T> l;
		for (auto node : adj)
		{
			if (!vis[node.fi])
				topological_sort_dfs_helper(node.fi, vis, l);
		}
		for (auto node : l)
			cout << node << " ";
		cout << endl;
	}
	void topological_sort_bfs()
	{
		unordered_map<T, int> indegree;
		for (auto node : adj)
			indegree[node.fi] = 0;
		for (auto node : adj)
		{
			for (auto child : adj[node.fi])
				indegree[child]++;
		}
		queue<T> q;
		for (auto node : adj)
			if (indegree[node.fi] == 0)
				q.push(node.fi);
		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto child : adj[node])
			{
				indegree[child]--;
				if (indegree[child] == 0)
					q.push(child);
			}
		}
	}
};
int32_t main()
{
	fast();
	int n;	cin >> n;
	Graph<string> g;
	for (int i = 0; i < n; i++)
	{
		string x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	g.topological_sort_dfs();
	g.topological_sort_bfs();
	return 0;
}