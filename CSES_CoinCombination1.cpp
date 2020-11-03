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
int m, n;
vector<int> coins;
vector<int> dp;
int solve(int n)
{
	// base case
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	int ways = 0;
	for (auto coin : coins)
	{
		if (n - coin >= 0)
			ways += solve(n - coin);
		ways %= mod;
	}
	return dp[n] = ways % mod;
}
int32_t main()
{
	fast();
	cin >> m >> n;
	coins.resize(m);
	for (int i = 0; i < m; i++)	cin >> coins[i];
	dp.resize(n + 1, -1);
	cout << solve(n);
	return 0;
}