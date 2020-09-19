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

void solve(int index, vector<int> cost, vector<int> &dp)
{
	if (index == 0)
	{
		dp[index] = 1;
		return ;
	}
	if (dp[index] != -1)
	{
		return ;
	}
	int temp = 0;
	for (int j = 0; j < index; j++)
	{
		solve(j, cost, dp);
		if (cost[j] < cost[index])
		{
			temp = max(dp[j], temp);
		}
	}
	dp[index] = temp + 1;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> cost(n);
	for (int i = 0; i < n; i++)	cin >> cost[i];
	vector<int> dp(n, -1);
	solve(n - 1, cost, dp);
	for (int i = 0; i < n; i++)	cout << dp[i] << " ";
	return 0;
}
