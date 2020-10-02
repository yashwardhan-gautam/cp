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
int n, m;
vector<vector<pii> > adj;
void FloydWarshall()
{
	vector<vector<int> > dis(n, vector<int> (n, inf));
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = 0;
		for (auto child : adj[i])
		{
			dis[i][child.fi] = child.se;
		}
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	for (int i = 0; i < n; i++)
		if (dis[i][i] < 0)
			cout << "Negative cycle exists\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dis[i][j] == inf)
				cout << "inf ";
			else
				cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}
int32_t main()
{
	fast();
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;	cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	FloydWarshall();
	return 0;
}