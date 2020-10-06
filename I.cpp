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
vector<double> p;
vector<vector<double> > dp;
double solve(int index, int heads_needed)
{
	// base case
	if (heads_needed == 0)
		return 1.0;
	if (index == n)
		return 0.0;
	if (dp[index][heads_needed] != -1.0)
		return dp[index][heads_needed];
	double op1 = p[index] * solve(index + 1, heads_needed - 1);
	double op2 = (1 - p[index]) * solve(index + 1, heads_needed);
	return dp[index][heads_needed] = op1 + op2;
}
int32_t main()
{
	fast();
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++)	cin >> p[i];
	dp.resize(n + 1, vector<double>(n + 1, -1.0));
	cout << fixed << setprecision(11) << solve(0, n / 2 + 1);
	return 0;
}
