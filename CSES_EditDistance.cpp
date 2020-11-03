#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
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
string s1, s2;
vector<vector<int> > dp;
int solve(int i, int j)
{
	if (i == s1.size() and j == s2.size())
		return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s1[i] == s2[j])
		return dp[i][j] = solve(i + 1, j + 1);
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;
	if (i + 1 <= s1.size() and j + 1 <= s2.size())
		a = solve(i + 1, j + 1);
	if (i + 1 <= s1.size())
		b = solve(i + 1, j);
	if (j + 1 <= s2.size())
		c = solve(i, j + 1);
	return dp[i][j] = 1 + min(a, min(b, c));
}
int32_t main()
{
	fast();
	cin >> s1 >> s2;
	dp.resize(s1.size() + 1, vector<int> (s2.size() + 1, -1));
	cout << solve(0, 0);
	return 0;
}