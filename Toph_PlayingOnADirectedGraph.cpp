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
const int N = 505;

int ans[N];
int d[N][N];
int32_t main()
{
	fast();
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			d[i][j] = 1e9;
			d[i][i] = 0;
		}

	for (int i = 1; i <= n; i++) ans[i] = 1e9;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = w;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 1; i <= n; i++)
	{
		if (d[i][i] < 0)
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans[j] = min(ans[j], d[i][j]);

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	return 0;
}