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

int n, m, k;
vector<int> arr;
int dp[5001][5001];

int solve(int index, int count)
{
	if (index > n - m or count == k)
		return 0;
	if (dp[index][count] != -1)
		return dp[index][count];
	int op1 = 0, op2 = 0;
	for (int j = index; j < index + m; j++)
		op1 += arr[j];
	op1 += solve(index + m, count + 1);
	op2 = solve(index + 1, count);
	return dp[index][count] = max(op1, op2);
}
int32_t main()
{
	fast();
	cin >> n >> m >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
	return 0;
}
