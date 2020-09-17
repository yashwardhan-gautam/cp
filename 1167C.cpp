//https://codeforces.com/problemset/problem/1167/C
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
	vector<int> parent, rank, size;
	int total_components;
	dsu(int n)
	{
		parent.resize(n);
		rank.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
			size[i] = 1;
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
			size[a] += size[b];
			total_components--;
		}
	}
};
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	dsu d(n + 1);
	for (int i = 0; i < m; i++)
	{
		int t;	cin >> t;
		vector<int> v(t);
		for (int i = 0; i < t; i++)	cin >> v[i];
		for (int i = 0; i < t - 1; i++)
			d.join(v[i], v[i + 1]);
		//cout << v[i] << " ";
	}
	for (int i = 1; i <= n; i++)
		cout << d.size[d.get(i)] << " ";
	return 0;
}