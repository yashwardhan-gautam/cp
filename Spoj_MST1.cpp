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
vector<int> dp(20000001, -1);
int top_down(int n)
{
	if (n <= 1)
		return dp[n] = 0;
	if (dp[n] != -1)
		return dp[n];
	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
	if (n > 1)
		op1 = 1 + top_down(n - 1);
	if (n % 2 == 0)
		op2 = 1 + top_down(n / 2);
	if (n % 3 == 0)
		op3 = 1 + top_down(n / 3);
	return dp[n] = min(op1, min(op2, op3));
}
void bottom_up()
{
	dp[1] = 0, dp[0] = 0;
	for (int i = 2; i <= 20000000; i++)
	{
		dp[i] = 1 + dp[i - 1];
		if (i % 2 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 2]);
		if (i % 3 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 3]);
	}
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	int count = 1;
	while (test--)
	{
		int n;	cin >> n;
		cout << "Case " << count << ": " << top_down(n) << "\n";
		count++;
	}
	return 0;
}