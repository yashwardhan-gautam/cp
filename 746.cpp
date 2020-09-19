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
int solve(vector<int> cost, int i, int n, vector<int> &dp)
{
	if (i >= n)
		return 0;
	if (dp[i] != -1)   return dp[i];
	int op1, op2;
	op1 = op2 = INT_MAX;
	op1 = solve(cost, i + 1, n, dp) + cost[i];
	op2 = solve(cost, i + 2, n, dp) + cost[i];
	dp[i] = min(op1, op2);
	return dp[i];
}
int minCostClimbingStairs(vector<int>& cost)
{
	vector<int> dp(cost.size() + 1);
	for (int i = 0; i <= cost.size(); i++) dp[i] = -1;
	int op1 = solve(cost, 0, cost.size(), dp);
	for (int i = 0; i <= cost.size(); i++) dp[i] = -1;
	int op2 = solve(cost, 1, cost.size(), dp);
	return min(op1, op2);
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> cost(n);
	for (int i = 0; i < n; i++)	cin >> cost[i];
	cout << minCostClimbingStairs(cost) << endl;
	return 0;
}
