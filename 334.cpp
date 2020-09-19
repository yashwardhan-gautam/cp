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
string s;
vector<vector<int> > dp;
int solve(int i, int j, string s)
{
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = solve(i + 1, j, s) + 1;
	for (int k = i + 1; k <= j; k++)
	{
		if (s[i] == s[k])
		{
			ans = min(ans, solve(i, k - 1, s) + solve(k + 1, j, s));
		}
	}
	return dp[i][j] = ans;
}
int32_t main()
{
	fast();
	cin >> s;
	int n = s.size();
	dp.resize(n + 1, vector<int> (n + 1, -1));
	cout << solve(0, n - 1, s);
	return 0;
}
