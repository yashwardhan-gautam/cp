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

int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	vector<int> a(n);
	vector<int> g[m];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		g[a[i] % m].pb(i);
	}
	int k = n / m;
	vector<pii> v;
	int ans = 0;
	for (int i = 0; i <= 2 * m; i++)
	{
		int curr = i % m;
		while (g[curr].size() > k)
		{
			v.pb({g[curr].back(), curr});
			g[curr].pop_back();
		}
		while (g[curr].size()<k and v.size()>0)
		{
			pii p = v.back();
			v.pop_back();
			int inc = (curr - p.se + m) % m;
			ans += inc;
			a[p.fi] += inc;
			g[curr].pb(p.fi);
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}