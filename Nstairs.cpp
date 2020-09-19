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


int solve(int n, int k)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	int ans = 0;
	for (int i = 1; i < ja = k; i++)
		ans += solve(n - i, k);
	return ans;
}
int32_t main()
{
	fast();
	int n, k;	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}
