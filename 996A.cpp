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
vector<int> dp;
int solve(int n)
{
	if (n == 0)
		return 0;
	if (n < 0)
		return INT_MAX;
	if (n == 1 or n == 5 or n == 10 or n == 20 or n == 100)
		return dp[n] = 1;
	if (dp[n] != -1)
		return dp[n];
	int ans = INT_MAX;
	ans = min(ans, solve(n - 1) + 1);
	ans = min(ans, solve(n - 5) + 1);
	ans = min(ans, solve(n - 10) + 1);
	ans = min(ans, solve(n - 20) + 1);
	ans = min(ans, solve(n - 100) + 1);
	return dp[n] = ans;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	int ans = n / 100;
	n = n % 100;
	dp.resize(n + 1, -1);
	cout << ans + solve(n) << endl;
	return 0;
}