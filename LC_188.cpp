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
vector<vector<vector<int> > > dp;
int solve(vector<int> &prices, int k, int i, int count, bool flag)
{
	if (count == k)
		return 0;
	if (i == prices.size() - 1)
		return flag ? 0 : prices[i];
	if (dp[i][count][flag] != -1)
		return dp[i][count][flag];
	int ans = 0;
	if (flag)
		ans = max(solve(prices, k, i + 1, count, !flag) - prices[i], solve(prices, k, i + 1, count, flag));
	else
		ans = max(solve(prices, k, i + 1, count + 1, !flag) + prices[i], solve(prices, k, i + 1, count, flag));
	return dp[i][count][flag] = ans;
}
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	if (!n)
		return 0;
	if (2 * k > n) {
		int res = 0;
		for (int i = 1; i < n; i++)
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		return res;
	}
	dp.resize(n + 1, vector<vector<int > >(k + 1, vector<int>(2, -1)));
	return solve(prices, k, 0, 0, 1);
}
int32_t main()
{
	fast();
	int n, k;	cin >> n >> k;
	vector<int> prices(n);
	for (int i = 0; i < n; i++)	cin >> prices[i];
	cout << maxProfit(k, prices) << endl;
	return 0;
}