//CycleDetectionUndirectedGraph.cpp
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
template<typename T>
// Cycle detection in undirected graph using BFS and DFS
class Graph
{
	unordered_map<int, list<int> > adj;
	bool cycle_present(T node, unordered_map<T, bool> &vis, T parent)
	{
		vis[node] = true;
		for (auto child : adj[node])
		{
			if (vis[child] and child != parent)
				return true;
			if (!vis[child])
				return cycle_present(child, vis, node);
		}
		return false;
	}
public:
	void addEdge(T u, T v, bool bidir = true)
	{
		adj[u].pb(v);
		if (bidir)
			adj[v].pb(u);
	}
	bool dfs_cycle_detection()
	{
		unordered_map<T, bool> vis;
		for (auto node : adj)
			if (!vis[node.fi] and cycle_present(node.fi, vis, node.fi))
				return true;
		return false;
	}
	bool bfs_cycle_detection(T src)
	{
		unordered_map<T, bool> vis;
		unordered_map<T, T> parent;
		parent[src] = src;
		vis[src] = true;
		queue<T> q;
		q.push(src);
		while (!q.empty())
		{
			T node = q.front();	q.pop();
			for (auto child : adj[node])
			{
				// if the child is visited and not a parent of the current node
				if (vis[child] and child != parent[node])
					return true;
				if (!vis[child])
				{
					vis[child] = true;
					parent[child] = node;
					q.push(child);
				}
			}
		}
		return false;
	}
};
int32_t main()
{
	fast();
	int n;	cin >> n;
	Graph<int> g;
	for (int i = 0; i < n; i++)
	{
		int u, v;	cin >> u >> v;
		g.addEdge(u, v, true);
	}
	cout << g.dfs_cycle_detection() << endl;
	cout << g.bfs_cycle_detection(1) << endl;
	return 0;
}