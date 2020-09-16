//KruskalAlgorithm
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
class dsu
{
public:
	vector<int> parent, rank;
	int total_components;
	dsu(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		total_components = n;
	}
	int get(int a)
	{
		if (a == parent[a])
			return a;
		return parent[a] = get(parent[a]);
	}
	void join(int a, int b)
	{
		a = get(a);
		b = get(b);
		if (a != b)
		{
			if (rank[b] > rank[a])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				rank[a]++;
			total_components--;
		}
	}
};
struct Edge
{
	int u, v, weight;
};
bool compare(Edge a, Edge b)
{
	return a.weight < b.weight;
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].weight;
	sort(edges.begin(), edges.end(), compare);
	dsu d(n + 1);
	int cost = 0;
	for (int i = 0; i < m; i++)
	{
		if (d.get(edges[i].u) != d.get(edges[i].v))
		{
			cout << edges[i].u << " to " << edges[i].v << " with weight " << edges[i].weight << endl;
			d.join(edges[i].u, edges[i].v);
			cost += edges[i].weight;
		}
	}
	cout << cost << endl;

	return 0;
}