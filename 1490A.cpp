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
int solve1(int a, int b)
{
	int a1 = min(a, b);
	int b1 = max(a, b);
	int c = 0;
	while ((b1 * 1.0 / a1 * 1.0) > 2.0)
	{
		a1 *= 2;
		c++;
	}
	return c;
}
void solve()
{
	int n;	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int res = 0;
	for (int i = 0; i < n - 1; i++)
		res += solve1(v[i], v[i + 1]);
	cout << res << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}