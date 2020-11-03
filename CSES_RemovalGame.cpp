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
int n;
vector<int> v;
int32_t main()
{
	fast();
	cin >> n;	v.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++)	cin >> v[i], sum += v[i];
	vector<vector<int> > dp(n, vector<int> (n));
	for (int l = n - 1; l >= 0; l--)
	{
		for (int r = l; r < n; r++)
		{
			if (l == r)
				dp[l][r] = v[l];
			else
				dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
		}
	}
	cout << (sum + dp[0][n - 1]) / 2;
	return 0;
}