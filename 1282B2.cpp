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
		int n, p, k;	cin >> n >> p >> k;
		vector<int> dp(n), a(n);
		for (int i = 0; i < n; i++)	cin >> a[i];
		sort(a.begin(), a.end());
		dp[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			if (i < (k - 1))
				dp[i] = a[i] + dp[i - 1];
			else if (i == k - 1)
				dp[i] = a[i];
			else
				dp[i] = a[i] + dp[i - k];
		}
		//for (int i = 0; i < n; i++)	cout << dp[i] << " ";	cout << endl;
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (dp[i] <= p)
				ans = i + 1;
		cout << ans << endl;
	}
	return 0;
}