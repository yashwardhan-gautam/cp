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
int solve()
{
	int n, m, k;	cin >> n >> m >> k;
	vector<pii> v(k);
	vector<int> d1(n + 1, 0), d2(m + 1, 0);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i].fi;
		d1[v[i].fi]++;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> v[i].se;
		d2[v[i].se]++;
	}
	int ans = (k * (k - 1)) >> 1;
	for (int i = 1; i <= n; i++)
		ans -= (d1[i] * (d1[i] - 1)) >> 1;
	for (int i = 1; i <= m; i++)
		ans -= (d2[i] * (d2[i] - 1)) >> 1;
	return ans;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		cout << solve() << endl;
	return 0;
}