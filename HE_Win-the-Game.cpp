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
double solve(int r, int g, vector<vector<double> > &dp)
{
	// Base Case
	if (g <= 0) return 1.0;
	// if there's no red to pull out, satyam wins
	if (r == 0) return 1.0;
	if (dp[r][g] != -1.0)
		return dp[r][g];
	return dp[r][g] = (r * 1.0 / ((r + g) * 1.0)) + (g * 1.0 / ((r + g) * 1.0)) * ((g - 1) * 1.0 / ((r + g - 1) * 1.0)) * solve(r, g - 2, dp);

}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int r, g;	cin >> r >> g;
		vector<vector<double> > dp(r + 1, vector<double> (g + 1, -1.0));
		cout << fixed << setprecision(6) << solve(r, g, dp) << endl;
	}
	return 0;
}