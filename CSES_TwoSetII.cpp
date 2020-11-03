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
int n;
vector<vector<int> > dp;
int solve(int i, int sum)
{
	if (sum == 0)
		return 1;
	if (i == n)
		return 0;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	int ans = solve(i + 1, sum) % mod;
	if (sum - i >= 0)
		ans += solve(i + 1, sum - i) % mod;
	return dp[i][sum] = ans % mod;
}
int32_t main()
{
	fast();
	cin >> n;
	int sum = (n * (n + 1)) / 2;
	if (sum & 1)
	{
		cout << "0\n";
		return 0;
	}
	int t = (n * (n + 1)) / 4;
	dp.resize(n + 1, vector<int> (t + 1, -1));
	cout << solve(1, (n * (n + 1)) / 4);
	return 0;
}