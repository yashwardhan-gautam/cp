#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
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

int32_t main()
{
	fast();
	int n, x;
	cin >> n >> x;
	vector<int> price(n + 1), pages(n + 1);
	for (int i = 1; i <= n; i++)	cin >> price[i];
	for (int i = 1; i <= n; i++)	cin >> pages[i];
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			dp[i][j] = dp[i - 1][j];
			int left = j - price[i];
			if (left >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i]);
		}
	}
	cout << dp[n][x];
	return 0;
}