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
int n;
vector<int> h;
vector<int> dp;
int solve(int i)
{
	if (i == n - 1)
		return 0;
	if (dp[i] != -1)
		return dp[i];
	int ans = INT_MAX;
	ans = min(ans, abs(h[i] - h[i + 1]) + solve(i + 1));
	if (i + 2 < n)
		ans = min(ans, abs(h[i] - h[i + 2]) + solve(i + 2));
	return dp[i] = ans;
}
int32_t main()
{
	fast();
	cin >> n;
	h.resize(n);
	dp.resize(n, -1);
	for (int i = 0; i < n; i++)	cin >> h[i];
	cout << solve(0);
	return 0;
}