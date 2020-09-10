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
#define inf             1e9
#define endl		 	      "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	fast();
	int a, n, m;	cin >> a >> n >> m;
	vector<int> rain(a + 1, 0);
	vector<pair<int, int> > umb(a + 1, make_pair(inf, -1));
	vector<int> cost(m);
	for (int i = 0; i < n; i++)
	{
		int l, r;	cin >> l >> r;
		for (int j = l; j < r; j++)
			rain[j] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, p;
		cin >> x >> p;
		cost[i] = p;
		umb[x] = min(umb[x], make_pair(p, i));
	}
	for (int i = 0; i <= a; i++)	cout << i << " ";	cout << endl;
	for (int i = 0; i <= a; i++)	cout << rain[i] << " ";	cout << endl;
	for (int i = 0; i <= a; i++)	cout << umb[i].fi << " " << umb[i].se << endl;

	vector<vector<int> > dp(a + 1, vector<int>(m + 1, inf));
	dp[0][m] = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i][j] == inf)
				continue;
			if (rain[i] == 0)
				dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
		}
	}
	return 0;
}