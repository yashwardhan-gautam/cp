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
	ll n;
	cin >> n;
	ll arr[n + 5], dp[n + 5], temp[n + 5];
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 0;
		temp[i] = 0;
	}
	dp[0] = 1;
	for (ll i = 0; i < n - 1; i++)
	{
		if (i > 1)
			dp[i] = (dp[i] + dp[i - 1]) % mod;
		dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
		if (i + arr[i] + 1 < n)
			dp[i + arr[i] + 1] = (dp[i + arr[i] + 1] - dp[i] + mod) % mod;
	}
	if (n >= 2)
		dp[n - 1] = (dp[n - 1] + dp[n - 2]) % mod;
	cout << dp[n - 1] << endl;
}