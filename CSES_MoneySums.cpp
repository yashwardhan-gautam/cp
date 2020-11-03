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
	int n;	cin >> n;
	int max_sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)	cin >> a[i], max_sum += a[i];
	vector<vector<bool> > dp(n + 1, vector<bool> (max_sum + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= max_sum; j++)
		{
			dp[i][j] = dp[i - 1][j];
			int left = j - a[i - 1];
			if (left >= 0 and dp[i - 1][left])
				dp[i][j] = true;
		}
	}
	vector<int> p;
	for (int j = 1; j <= max_sum; j++)
	{
		if (dp[n][j])
			p.pb(j);
	}
	cout << p.size() << endl;
	for (auto it : p)
		cout << it << " ";
	cout << endl;
	return 0;
}