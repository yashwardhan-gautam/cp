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
int n, m;
vector<int> a, b;
vector<vector<int> > dp;
int solve(int i, int j)
{
	if (i == a.size() or j == b.size())
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MIN;
	if (abs(a[i] - b[j]) <= 1)
		ans = max(ans, 1 + solve(i + 1, j + 1));
	ans = max(ans, max(solve(i + 1, j), solve(i, j + 1)));
	return dp[i][j] = ans;
}
int32_t main()
{
	fast();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; i++)	cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	dp.resize(n + 1, vector<int> (m + 1, -1));
	cout << solve(0, 0);
	return 0;
}