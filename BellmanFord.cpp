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
vector<vector<int> > edges;
void BellmanFord(int src)
{
	vector<int> dis(n, inf);
	dis[src] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		// Relaxing all the edges n-1 times
		for (int j = 0; j < m; j++)
		{
			if (dis[edges[j][0]] != inf and dis[edges[j][1]] > dis[edges[j][0]] + edges[j][2])
				dis[edges[j][1]] =	dis[edges[j][0]] + edges[j][2];
		}
	}
	// checking for negative cycle
	for (int j = 0; j < m; j++)
	{
		if (dis[edges[j][0]] != inf and dis[edges[j][1]] > dis[edges[j][0]] + edges[j][2])
		{
			cout << "negative cycle exists\n";
			return ;
		}
	}
	for (int i = 0; i < n; i++)
		cout << i << "--" << dis[i] << endl;
}
int32_t main()
{
	fast();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;	cin >> u >> v >> w;
		edges.pb({u, v, w});
	}
	BellmanFord(0);
	return 0;
}