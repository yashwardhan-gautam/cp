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
class Graph {
	int v;
	list<pii> *l;
public:
	Graph(int V)
	{
		v = V;
		l = new list<pii>[V];
	}
	void addEdge(int u, int v, int w)
	{
		l[u].pb({v, w});
		l[v].pb({u, w});
	}
	int find_min(unordered_map<int, bool> &vis, unordered_map<int, int> &weight, int v)
	{
		int minvertex = -1;
		for (int i = 0; i < v; i++)
		{
			if (!vis[i] and (minvertex == -1 or (weight[i] < weight[minvertex])))
				minvertex = i;
		}
		return minvertex;
	}
	void Prims()
	{
		unordered_map<int, bool> vis;
		unordered_map<int, int> parent;
		unordered_map<int, int> weight;
		for (int i = 0; i < v; i++)
			vis[i] = false, weight[i] = inf;
		parent[0] = -1;
		weight[0] = 0;
		for (int i = 0; i < v - 1; i++)
		{
			int minvertex = find_min(vis, weight, v);
			vis[minvertex] = true;
			for (auto child : l[minvertex])
			{
				if (!vis[child.fi] and weight[child.fi] > child.se)
					weight[child.fi] = child.se, parent[child.fi] = minvertex;
			}
		}
		for (int i = 1; i < v; i++)
		{
			cout << i + 1 << "--" << parent[i] + 1 << " with weight " << weight[i] << endl;
		}
	}
};
int n, m;
int32_t main()
{
	fast();
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g.addEdge(u, v, w);
	}
	g.Prims();
	return 0;
}