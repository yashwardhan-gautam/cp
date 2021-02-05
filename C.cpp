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
#define endl			"\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGEki
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n;
vector<vector<int> > points;
vector<vector<int> > dp;
int solve(int index, int activity)
{
	if (index == n)
		return 0;

	if (dp[index][activity] != -1)
		return dp[index][activity];
	int ans = points[index][activity];
	if (activity == 0)
		ans += max(solve(index + 1, 1), solve(index + 1, 2));
	else if (activity == 1)
		ans += max(solve(index + 1, 0), solve(index + 1, 2));
	else if (activity == 2)
		ans += max(solve(index + 1, 0), solve(index + 1, 1));
	return dp[index][activity] = ans;
}
int32_t main()
{
	fast();
	cin >> n;
	points.resize(n, vector<int> (3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> points[i][j];
	}
	dp.resize(n, vector<int> (3, -1));
	cout << max(solve(0, 0), max(solve(0, 1), solve(0, 2)));
	return 0;
}