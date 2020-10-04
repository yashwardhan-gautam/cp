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
string shortes_common_supersequence(string X, string Y)
{
	int n = X.length();
	int m = Y.length();
	int dp[m + 1][n + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string str;
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			str.push_back(X[i - 1]);
			i--, j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			str.push_back(Y[j - 1]);
			j--;
		}
		else
		{
			str.push_back(X[i - 1]);
			i--;
		}
	}
	while (i > 0)
	{
		str.push_back(X[i - 1]);
		i--;
	}

	while (j > 0)
	{
		str.push_back(Y[j - 1]);
		j--;
	}
	reverse(str.begin(), str.end());
	return str;
}
int32_t main()
{
	fast();
	while (!cin.eof())
	{
		string s1, s2;	cin >> s1 >> s2;
		cout << shortes_common_supersequence(s1, s2) << endl;
	}
	return 0;
}