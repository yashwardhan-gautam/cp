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
int find_max_index(vector<int> &v, int s, int e)
{
	if (s == e) return s;
	int idx = s;
	for (int i = s + 1; i <= e; i++)
	{
		if (v[i] > v[idx])
			idx = i;
	}
	return idx;
}
void solve1(vector<int> v, int s, int e, vector<int> &dp, int count)
{
	if (s > e) return ;
	int it = find_max_index(v, s, e);
	dp[it] = count;
	solve1(v, s, it - 1, dp, count + 1);
	solve1(v, it + 1, e, dp, count + 1);
}
void solve()
{
	int n;	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int s = 0, e = n - 1;
	vector<int> dp(n, -1);
	int count = 0;
	solve1(v, s, e, dp, count);
	for (auto it : dp)
		cout << it << " ";
	cout << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}