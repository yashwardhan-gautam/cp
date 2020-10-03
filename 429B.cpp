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
#define N 1005
int a[N][N];
int dp[N][N][5];
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	memset(dp, 0, sizeof(dp));
	// boy start
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j][1] = a[i][j] + max(dp[i - 1][j][1], dp[i][j - 1][1]);
	// boy end
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			dp[i][j][2] = a[i][j] + max(dp[i + 1][j][2], dp[i][j + 1][2]);
	// girl start
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			dp[i][j][3] = a[i][j] + max(dp[i + 1][j][3], dp[i][j - 1][3]);
	// girl end
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			dp[i][j][4] = a[i][j] + max(dp[i - 1][j][4], dp[i][j + 1][4]);
	int ans = 0;
	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 2; j <= m - 1; j++)
		{
			int ans1 = dp[i][j - 1][1] + dp[i][j + 1][2] + dp[i + 1][j][3] + dp[i - 1][j][4];
			int ans2 = dp[i - 1][j][1] + dp[i + 1][j][2] + dp[i][j - 1][3] + dp[i][j + 1][4];
			ans = max(ans, max(ans1, ans2));
		}
	}
	cout << ans << endl;
	return 0;
}