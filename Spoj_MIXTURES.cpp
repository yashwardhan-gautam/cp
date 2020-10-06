#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             long long unsigned
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
	while (!cin.eof())
	{
		int n;	cin >> n;
		int col[n][n];
		for (int i = 0; i < n; i++)	cin >> col[i][i];
		int dp[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = 10000000000000000;

		for (int i = 0; i < n; i++)	dp[i][i] = 0;

		for (int l = 2; l <= n; l++)
		{
			int e = n - l;
			for (int i = 0; i <= e; i++)
			{
				int k = i + l - 1;
				for (int j = i; j < k; j++)
				{
					int sm = dp[i][j] + dp[j + 1][k] + col[i][j] * col[j + 1][k];
					int cl = (col[i][j] + col[j + 1][k]) % 100;
					if (sm < dp[i][k]) {
						dp[i][k] = sm;
						col[i][k] = cl;
					}
				}
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	return 0;
}