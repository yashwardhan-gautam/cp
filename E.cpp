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
int n, capacity;
int dp[101][100001];
vector<int> w, v;

int solve(int max_profit)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= max_profit; j++)
		{
			if (i == 0 and j == 0)
				dp[i][j] = 0;
			else if (i == 0)
				dp[i][j] = inf;
			else if (v[i - 1] <= j)
				dp[i][j] = min(w[i - 1] + dp[i - 1][j - v[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	int ans = 0;
	for (int j = 0; j <= max_profit; j++)
	{
		if (dp[n][j] <= capacity)
			ans = j;
	}
	return ans;
}
int32_t main()
{
	fast();
	cin >> n >> capacity;
	w.resize(n);	v.resize(n);
	int max_profit = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> v[i];
		max_profit += v[i];
	}
	cout << solve(max_profit);
	return 0;
}
