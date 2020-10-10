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
// pos,tight, mo(given string mod m must be zero)
// st(the number has started or not)
// even(if the given index is even or not)
int dp[ 2005 ][ 2005 ][ 2 ][ 2 ][ 2 ];
string s;
string a, b;
int d, m;
int solve(int pos, int mo, bool tight, bool st, bool even)
{
	if (pos == s.size())
		return mo == 0;

	if (dp[pos][mo][tight][st][even] != -1)
		return dp[pos][mo][tight][st][even];

	int ans = 0;
	int end = (tight ? (s[pos] - '0') : 9);
	if (st == 0)
	{
		ans = (ans + solve(pos + 1, mo, tight & (s[pos] == '0'), st, 0)) % mod;
		for (int i = 1; i <= end ; i++)
		{
			if (i != d)
				ans = (ans + solve(pos + 1, (mo * 10 + i) % m, tight & (i == end), 1, 1)) % mod;
		}
	}
	else
	{
		for (int i = 0 ; i <= end ; i++)
		{
			if (even and (i == d))
				ans = (ans + solve(pos + 1, (mo * 10 + i) % m, tight & (i == end), 1, !even)) % mod;
			else if ( (!even) and (i != d))
				ans = (ans + solve(pos + 1, (mo * 10 + i) % m, tight & (i == end), 1, !even)) % mod;
		}
	}
	return dp[pos][mo][tight][st][even] = ans;
}

int32_t main() {
	fast();
	cin >> m >> d;
	cin >> a >> b;
	s = b;
	memset(dp, -1, sizeof dp);
	int ans = (solve(0, 0, 1, 0, 0)) % mod;
	s = a;
	memset(dp, -1, sizeof dp);
	ans =  (ans - solve(0, 0, 1, 0, 0) + mod) % mod;

	int mo = 0;
	bool flag = true;
	for (int i = 0; i < a.size() ; i++)
	{
		if (i % 2 and ((a[i] - '0') != d ))
		{
			flag = false;
			break;
		}
		if (i % 2 == 0 and ((a[i] - '0') == d))
		{
			flag = false;
			break;
		}
		mo = (mo * 10 + (a[i] - '0')) % m;
	}
	if ( mo == 0 and flag)
		ans = (ans + 1) % mod;

	cout << ans << endl;
	return 0;
}