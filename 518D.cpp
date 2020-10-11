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
	double p;
	int n, t;	cin >> n >> p >> t;
	double dp[t + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int time = 0; time < t; time++)
	{
		for (int people = 0; people < n; people++)
		{
			dp[time + 1][people] += (1 - p) * dp[time][people];
			dp[time + 1][people + 1] += p * dp[time][people];
		}
		dp[time + 1][n] += dp[time][n];
	}
	double ans = 0.0;
	for (int people = 0; people <= n; people++)
		ans += dp[t][people] * people;
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
/*
for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j) // if there are some persons on escalator
				dp[i][j] += dp[i - 1][j - 1] * p;
			if (j == n)
				dp[i][j] += dp[i - 1][j];
			else
				dp[i][j] += dp[i - 1][j] * (1 - p);
		}
	}
*/