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
int solve(int index, int n, bool last_day_vis_or_not, vector<vector<int> > &dp)
{
	if (index == n)
		return 1;
	if (dp[index][last_day_vis_or_not] != -1)
		return dp[index][last_day_vis_or_not] % mod;
	if (index == 0)
		return dp[index][last_day_vis_or_not] = (solve(1, n, true, dp) % mod + solve(1, n, false, dp) % mod) % mod;
	if (last_day_vis_or_not)
		return dp[index][last_day_vis_or_not] = (solve(index + 1, n, false, dp) % mod);
	else
		return dp[index][last_day_vis_or_not] = (solve(index + 1, n, true, dp) % mod + solve(index + 1, n, false, dp) % mod);
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int n;	cin >> n;
		vector<vector<int> > dp(n + 1, vector<int> (2, -1));
		cout << solve(0, n, false, dp) % mod << endl;
	}
	return 0;
}

