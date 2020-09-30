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
void BFS01(int s)
{
	deque<int> q;
	vector<bool> vis(n, false);
	vector<int> dis(n);
	dis[s] = 0;
	vis[s] = true;
	q.push_back(s);
	while (!q.empty())
	{
		int curr = q.front();	q.pop_front();
		for (auto child : adj[curr])
		{
			if (!vis[child.fi])
			{
				dis[child.fi] = dis[curr] + child.se;
				vis[child.fi] = true;
				if (child.se == 1)
					q.push_back(child.fi);
				else
					q.push_front(child.fi);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << i << " " << dis[i] << "\n";
}
int32_t main()
{
	fast();
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;	cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	BFS01(1);
	return 0;
}