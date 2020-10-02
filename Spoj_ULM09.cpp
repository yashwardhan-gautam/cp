// https://www.spoj.com/problems/ULM09/
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
// DSU with elements 0,1,2....n-1
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
int n, m;
struct edge {
	int u, v, w;
};
bool compare(edge a, edge b)
{
	return a.w < b.w;
}
int32_t main()
{
	fast();
	while (1)
	{
		cin >> n >> m;
		if (n == 0 and m == 0)
			break;
		dsu d(n);
		vector<edge> e(m);
		int total_sum = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> e[i].u >> e[i].v >> e[i].w;
			total_sum += e[i].w;
		}
		sort(e.begin(), e.end(), compare);
		for (int i = 0; i < e.size(); i++)
		{
			if (d.get(e[i].u) != d.get(e[i].v))
			{
				total_sum -= e[i].w;
				d.join(e[i].u, e[i].v);
			}
		}
		cout << total_sum << "\n";
	}
	return 0;
}