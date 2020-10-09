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
int dp[ 20 ][ 4 ][ 2 ];
int l, r;
string s;

int solve(int pos, int cnt, bool tight)
{
	if (pos == s.length())
		return 1;
	if (dp[pos][cnt][tight] != -1)
		return dp[pos][cnt][tight];

	int ans = 0;

	int end = ((tight) ? (s[pos] - '0') : 9);
	for (int i = 0; i <= end ; i++)
	{
		int cntupd = cnt + (i > 0);
		if (cntupd <= 3)
			ans += solve(pos + 1, cntupd, tight & (i == end));
	}
	return dp[pos][cnt][tight] = ans;
}
int32_t main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> l >> r;
		memset(dp, -1, sizeof(dp));
		s = to_string(r);
		int ans = solve(0, 0, 1);
		l -= 1;
		memset(dp, -1, sizeof(dp));
		s = to_string(l);
		ans -= solve(0, 0, 1);
		cout << ans << endl;
	}
	return 0;
}