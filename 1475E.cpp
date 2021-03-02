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
int ncr(int n, int r, int p)
{
	vector<int> c(r + 1, 0);
	c[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = min(i, r); j > 0; j--)
		{
			c[j] = (c[j] + c[j - 1]) % p;
		}
	}
	return c[r];
}
int solve()
{
	int n, k;	cin >> n >> k;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		m[x]++;
	}
	vector<pii> v;
	for (auto it : m)
		v.pb({it.fi, it.se});
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++)
	{
		if (k - v[i].se <= 0)
		{
			//cout << v[i].se << " " << k << "\n";
			return ncr(v[i].se, k, mod);
		}
		k -= v[i].se;
	}
	return 1;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		cout << solve() << endl;
	return 0;
}