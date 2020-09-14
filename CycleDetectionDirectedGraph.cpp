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
// cycle detection in directed graph using DFS and BFS
// 1-cycle exist, 0-cycle does not exist
class Graph
{
	unordered_map<T, list<T> > adj;
	bool cycle_present(T node, unordered_map<T, bool> &vis, unordered_map<T, bool> &instack)
	{
		vis[node] = true;
		instack[node] = true;
		for (auto child : adj[node])
		{
			// if the child is not visited and is a part of cycle
			if (!vis[child] and cycle_present(child, vis, instack))
				return true;
			// if the child is instack
			if (instack[child])
				return true;
		}
		instack[node] = false;
		return false;
	}
public:
	void addEdge(T u, T v, bool bidir = false)
	{
		adj[u].pb(v);
		if (bidir)
			adj[v].pb(u);
	}
	bool dfs_cycle_detection()
	{
		unordered_map<T, bool> vis, instack;
		for (auto node : adj)
			vis[node.fi] = false, instack[node.fi] = false;
		for (auto node : adj)
		{
			if (!vis[node.fi])
				if (cycle_present(node.fi, vis, instack))
					return true;
		}
		return false;
	}
	//Khan's algorithm to find if cycle exists, if there's no cycle it prints topologically sorted list
	bool bfs_cycle_detection()
	{
		unordered_map<T, int> indegree;
		for (auto node : adj)
		{
			for (auto child : adj[node.fi])
				indegree[child]++;
		}
		queue<T> q;
		for (auto node : adj)
			if (indegree[node.fi] == 0)
				q.push(node.fi);
		list<T> l;
		while (!q.empty())
		{
			T node = q.front();	q.pop();
			l.push_back(node);
			for (auto child : adj[node])
			{
				indegree[child]--;
				if (indegree[child] == 0)
					q.push(child);
			}
		}
		if (l.size() != adj.size())
			return true;
		for (auto node : l)
			cout << node << " ";
		cout << endl;
		return false;
	}
};
int32_t main()
{
	fast();
	Graph<string> g;
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string x, y;	cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.dfs_cycle_detection() << endl;
	cout << g.bfs_cycle_detection() << endl;
	return 0;
}