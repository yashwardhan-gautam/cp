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
string s;
int dp[10005][105][2];
int d;
int solve(int pos, int sum, bool tight)
{
	if (pos == s.size())
		return sum == 0;
	if (dp[pos][sum][tight] != -1)
		return dp[pos][sum][tight];
	int end = ((tight) ? (s[pos] - '0') : 9);
	int ans = 0;
	for (int i = 0; i <= end; i++)
	{
		ans = (ans + solve(pos + 1, (sum + i) % d, tight & (i == end))) % mod;
		ans = ans % mod;
	}
	return dp[pos][sum][tight] = ans;
}
int32_t main()
{
	fast();
	cin >> s;
	cin >> d;
	memset(dp, -1, sizeof(dp));
	int ans = (solve(0, 0, 1) - 1 + mod) % mod;
	cout << ans << endl;
}