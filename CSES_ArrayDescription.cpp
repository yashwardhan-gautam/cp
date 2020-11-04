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
// dp[i][v] = number of ways to fill the array up to index i, if x[i]==v
int n, m;
int32_t main()
{
	fast();
	cin >> n >> m;
	vector<vector<int> > dp(n, vector<int> (m + 1, 0));
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	if (v[0] == 0)
		fill(dp[0].begin(), dp[0].end(), 1);
	else
		dp[0][v[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		if (!v[i])
		{
			for (int j = 1; j <= m; j++)
				for (int k = j - 1; k <= j + 1; k++)
					if (k >= 1 and k <= m)
						(dp[i][j] += dp[i - 1][k]) %= mod;
		}
		else
		{
			for (int k = v[i] - 1; k <= v[i] + 1; k++)
				if (k >= 1 and k <= m)
					(dp[i][v[i]] += dp[i - 1][k]) %= mod;
		}
	}
	int ans = 0;
	for (int j = 1; j <= m; j++)
		(ans += dp[n - 1][j]) %= mod;
	cout << ans;
	return 0;
}