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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int shift = 1e5;
int dp[101][200005];
int solve(int index, int n, int k, vector<int> taste, vector<int> calories, int sum)
{
	if (index == n)
	{
		if (sum == 0)
			return 0;
		else
			return -1e12;
	}
	if (dp[index][shift + sum] != -1)
		return dp[index][shift + sum];
	int option1 = taste[index] + solve(index + 1, n, k, taste, calories, sum + (taste[index] - k * calories[index]));
	int option2 = 0 + solve(index + 1, n, k, taste, calories, sum);
	return dp[index][shift + sum] = max(option2, option1);
}
int32_t main()
{
	fast();
	int n, k;	cin >> n >> k;
	vector<int> taste(n), calories(n);
	for (int i = 0; i < n; i++)	cin >> taste[i];
	for (int i = 0; i < n; i++)	cin >> calories[i];
	memset(dp, -1, sizeof(dp));
	int ans = solve(0, n, k, taste, calories, 0);
	if (!ans)
		cout << "-1";
	else
		cout << ans;
	return 0;
}
