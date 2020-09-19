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
int solve(string s, int i, int j, vector<vector<bool> > palin, vector<vector<int> > &dp)
{
	if (i == j or palin[i][j])
		return dp[i][j] = 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX - 1000;
	for (int k = i; k < j; k++)
		ans = min(ans, solve(s, i, k, palin, dp) + 1 + solve(s, k + 1, j, palin, dp));
	return dp[i][j] = ans;
}
int32_t main()
{
	fast();
	string s;	cin >> s;
	int n = s.size();
	vector<vector<bool> > palin(n, vector<bool> (n, 0));
	for (int i = 0; i < s.size(); i++)
		palin[i][i] = true;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == s[i + 1])
			palin[i][i + 1] = true;
	for (int l = 3; l <= s.size(); l++)
	{
		for (int i = 0; i <= n - l; i++)
		{
			int j = i + l - 1;
			if (s[i] == s[j] and palin[i + 1][j - 1] == true)
				palin[i][j] = true;
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (palin[i][j])
			{
				cout << s.substr(i, j - i + 1) << endl;
			}
		}
	}*/
	vector<vector<int> > dp(n, vector<int> (n, -1));
	cout << solve(s, 0, s.size() - 1, palin, dp);
	return 0;
}
