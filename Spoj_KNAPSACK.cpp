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
int w, n;
vector<int> weight, value;
vector<vector<int> > dp;
int solve(int index, int curr_weight) {
	// Base case
	if (curr_weight == w)
		return 0;
	if (index == n)
		return 0;
	if (dp[index][curr_weight] != -1)
		return dp[index][curr_weight];
	int op1 = INT_MIN, op2 = INT_MIN;
	if (curr_weight + weight[index] <= w)
		op1 = value[index] + solve(index + 1, curr_weight + weight[index]);
	op2 = 0 + solve(index + 1, curr_weight);
	return dp[index][curr_weight] = max(op1, op2);
}
int32_t main()
{
	fast();
	cin >> w >> n;
	weight.resize(n), value.resize(n);
	dp.resize(n, vector<int> (w + 1, -1));
	for (int i = 0; i < n; i++)	cin >> weight[i] >> value[i];
	cout << solve(0, 0);
	return 0;
}