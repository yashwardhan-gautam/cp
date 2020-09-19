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

int k;
vector<int> a, b;
vector<int> dp;
int solve(int len)
{
	if (len == 0)
		return dp[len] = 1;
	if (dp[len] != -1)
		return dp[len];
	int op1 = 0, op2 = 0;
	op1 = solve(len - 1);
	if (len - k >= 0)
		op2 = solve(len - k);
	return dp[len] = (op1 % mod + op2 % mod) % mod;
}
int32_t main()
{
	fast();
	int test;	cin >> test >> k;
	a.resize(test);
	b.resize(test);
	int bmax = 0;
	for (int i = 0; i < test; i++)
	{
		cin >> a[i] >> b[i];
		bmax = max(bmax, b[i]);
	}
	bmax = bmax;
	dp.resize(bmax + 1, -1);
	solve(bmax);
	vector<int> pre(dp);
	for (int i = 1; i < pre.size(); i++)
	{
		pre[i] += pre[i - 1] % mod;
		pre[i] = pre[i] % mod;
	}
	for (int i = 0; i < test; i++)
		cout << (pre[b[i]] % mod - pre[a[i] - 1] % mod + mod) % mod << endl;
	return 0;
}
