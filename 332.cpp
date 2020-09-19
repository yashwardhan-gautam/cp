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
int solve(int i, int sum, vector<int> coins, int amount, vector<vector<int>  > &dp)
{
	if (sum == amount)
		return 0;
	if (i == coins.size())
	{
		if (sum == amount)
			return 0;
		return INT_MAX;
	}
	if (sum > amount)
		return INT_MAX;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	int op1 = 1 + solve(i, sum + coins[i], coins, amount, dp);
	int op2 = 0 + solve(i + 1, sum, coins, amount, dp);
	return dp[i][sum] = min(op1, op2);

}
int coinChange(vector<int> coins, int amount)
{
	vector<vector<int> > dp(coins.size() + 1, vector<int> (amount + 1, -1));
	int ans = solve(0, 0, coins, amount, dp);
	if (ans == INT_MAX)
		return -1;
	else
		return ans;
}

int32_t main()
{
	fast();
	int n, amount;	cin >> n >> amount;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)	cin >> coins[i];
	cout << coinChange(coins, amount);
	return 0;
}
