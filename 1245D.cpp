//https://codeforces.com/problemset/problem/1245/D
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
struct edge
{
	int u, v, w;
};
bool compare(edge a, edge b)
{
	return a.w < b.w;
}
int n;
vector<int> x, y;
vector<int> c;
vector<int> k;
int32_t main()
{
	fast();
	cin >> n;
	x.resize(n + 1), y.resize(n + 1), c.resize(n + 1), k.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)	cin >> c[i];
	for (int i = 1; i <= n; i++)	cin >> k[i];
	dsu d(n + 1);
	vector<edge> e;
	for (int i = 1; i <= n; i++)
		e.pb({0, i, c[i]});
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int w = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			e.pb({i, j, w});
		}
	}
	sort(e.begin(), e.end(), compare);
	vector<int> v;
	vector<pii> ed;
	int cost = 0;
	for (int i = 0; i < e.size(); i++)
	{
		if (d.get(e[i].u) != d.get(e[i].v))
		{
			cost += e[i].w;
			d.join(e[i].u, e[i].v);
			if (min(e[i].u, e[i].v) == 0)
				v.pb(max(e[i].u, e[i].v));
			else
				ed.pb({e[i].u, e[i].v});
		}
	}
	cout << cost << "\n";
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << ed.size() << "\n";
	for (int i = 0; i < ed.size(); i++)
		cout << ed[i].fi << " " << ed[i].se << "\n";
	return 0;
}