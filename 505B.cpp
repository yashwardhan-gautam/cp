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
	void init(int n)
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
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	vector<dsu> d(m + 1);
	for (int i = 0; i <= m; i++)
		d[i].init(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;	cin >> a >> b >> c;
		d[c ].join(a, b);
		//cout << d[c ].get(a) << " " << d[c ].get(b) << endl;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;	cin >> a >> b;
		int ans = 0;
		for (int j = 1; j <= m; j++)
		{
			if (d[j].get(a) == d[j].get(b))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}