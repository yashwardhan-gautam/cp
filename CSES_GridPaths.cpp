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
int n;
vector<string> grid;
int solve()
{
	if (grid[0][0] == '*' or grid[n - 1][n - 1] == '*')
		return 0;
	vector<vector<int> > dp(n, vector<int> (n, 0));
	for (int j = 0; j < n; j++)
	{
		if (grid[0][j] == '*')
			break;
		dp[0][j] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (grid[i][0] == '*')
			break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (grid[i][j] == '*')	continue;
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			dp[i][j] %= mod;
		}
	}
	return (dp[n - 1][n - 1]) % mod;
}
int32_t main()
{
	fast();
	cin >> n;
	grid.resize(n);
	for (int i = 0; i < n; i++)	cin >> grid[i];
	cout << solve();
	return 0;
}