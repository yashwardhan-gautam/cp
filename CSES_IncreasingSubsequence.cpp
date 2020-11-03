/*#include<bits/stdc++.h>
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
	vector<int> a(n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	vector<int> dp(n, 1);
	int ans = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	cout << ans << endl;
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
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
	vector<int> dp;
	for (int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		auto it = lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end())
			dp.push_back(x);
		else
			*it = x;
	}
	cout << dp.size() << endl;
}