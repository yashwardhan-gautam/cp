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

int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		string s1, s2;	cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		int dp[n + 1][m + 1];
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (i == 0 and j == 0)	dp[i][j] = 0;
				else if (i == 0)	dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
		cout << dp[n][m] << "\n";
	}
	return 0;
}