//https://codeforces.com/problemset/problem/1332/C
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
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int n, k;	cin >> n >> k;
		string s;	cin >> s;
		dsu d(n);
		for (int i = 0; i < n / 2; i++)
			d.join(i, n - i - 1);
		for (int i = 0; k + i < n; i++)
			d.join(i, k + i);
		vector<vector<int> > v(n + 1, vector<int> (26, 0));
		for (int i = 0; i < n; i++)
			v[d.get(i)][s[i] - 'a']++;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (d.get(i) == i)
			{
				int sum = 0;
				int ma = 0;
				for (int j = 0; j < 26; j++)
				{
					sum += v[i][j];
					ma = max(ma, v[i][j]);
				}
				ans += sum - ma;
			}
		}
		cout << ans << endl;
	}
	return 0;
}