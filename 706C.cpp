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
int n;
vector<vector<string> > s;
vector<int> c;
vector<vector<int> > dp;
int32_t main()
{
	fast();
	cin >> n;
	c.resize(n + 1);
	for (int i = 1; i <= n; i++)	cin >> c[i];
	s.resize(n + 1, vector<string> (2));
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
	}
	dp.resize(n + 1, vector<int> (2, -1));
	dp[1][0] = 0;
	dp[1][1] = c[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i][1] = inf;
		if (s[i][0] >= s[i - 1][0])
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (s[i][0] >= s[i - 1][1])
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (s[i][1] >= s[i - 1][0])
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if (s[i][1] >= s[i - 1][1])
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	int ans = min(dp[n][0], dp[n][1]);
	if (ans == inf)
		ans = -1;
	cout << ans;
	return 0;
}
