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
int n, m, p;
vector<vector<int> > dp;
int solve()
{
	if (dp[0][0] == -1 or dp[n - 1][m - 1] == -1)
		return 0;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (dp[i][0] == -1)
			break;
		dp[i][0] = 1;
	}
	for (int j = 0; j < m; j++)
	{
		if (dp[0][j] == -1)
			break;
		dp[0][j] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (dp[i][j] == -1)
				continue;
			if (dp[i - 1][j] != -1)
				dp[i][j] += (dp[i - 1][j]) % mod;
			if (dp[i][j - 1] != -1)
				dp[i][j] += (dp[i][j - 1]) % mod;
			dp[i][j] %= mod;
		}
	}
	return dp[n - 1][m - 1];
}
int32_t main()
{
	fast();
	cin >> n >> m >> p;
	dp.resize(n, vector<int> (m, 0));
	for (int i = 0; i < p; i++)
	{
		int u, v;	cin >> u >> v;
		u--, v--;
		dp[u][v] = -1;
	}
	cout << solve();
	return 0;
}