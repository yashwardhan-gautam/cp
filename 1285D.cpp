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

int solve(vector<int> a, int bit)
{
	if (a.size() == 0 or bit < 0)
		return 0;
	vector<int> zeros, ones;
	int mask = (1 << bit);
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]&mask)
			ones.push_back(a[i]);
		else
			zeros.push_back(a[i]);
	}
	if (zeros.size() == 0)
		return solve(ones, bit - 1);
	else if (ones.size() == 0)
		return solve(zeros, bit - 1);
	return (min(solve(ones, bit - 1), solve(zeros, bit - 1)) + (1 << bit));
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	cout << solve(v, 30) << endl;
	return 0;
}
