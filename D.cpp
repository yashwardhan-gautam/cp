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
#define endl			"\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int solve(int W, vector<int> w, vector<int> v, int i, vector<vector<int> > &dp)
{
	// Base cases
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	return dp[i][W];
	if (w[i] > W)
		return dp[i][W] = solve(W, w, v, i - 1, dp);

	else
		return dp[i][W] = max(v[i] + solve(W - w[i], w, v, i - 1, dp), solve(W, w, v, i - 1, dp));
}

int32_t main()
{
	fast();
	int n, W;	cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)	cin >> w[i] >> v[i];
	vector<vector<int> > dp(n + 1, vector<int> (W + 1, -1));
	cout << solve(W, w, v, n - 1, dp);
	return 0;
}