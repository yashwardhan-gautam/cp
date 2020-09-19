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

int n;
vector<pair<int, int> > v;
vector<int> dp;

int solve(int index)
{
	if (index >= v.size())
		return 0;
	if (dp[index] != -1)
		return dp[index];
	int op1 = INT_MIN, op2 = INT_MIN;
	if (index < v.size() - 1 and v[index + 1].first == v[index].first + 1)
		op1 = v[index].first * v[index].second + solve(index + 2);
	else
		op1 = v[index].first * v[index].second + solve(index + 1);
	op2 = 0 + solve(index + 1);
	return dp[index] = max(op1, op2);
}
int32_t main()
{
	fast();
	cin >> n;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int t;	cin >> t;
		m[t]++;
	}
	for (auto x : m)
	{
		pair<int, int> t;
		t.first = x.first;
		t.second = x.second;
		v.pb(t);
	}
	sort(v.begin(), v.end());
	dp.resize(v.size(), -1);
	cout << solve(0);
	return 0;
}