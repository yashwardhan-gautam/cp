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
// Dijsktra works on both directed and undirected Graphs
vector<bool> vis;
vector<vector<pii> > adj;
vector<int> dis;
int n, m;
void Dijsktra_set(int src)
{
	dis.resize(n, inf);
	dis[src] = 0;
	set<pii> s;
	s.insert({dis[src], src});
	while (!s.empty())
	{
		int curr = s.begin()->se;
		s.erase(s.begin());
		for (auto child : adj[curr])
		{
			if (dis[child.fi] > dis[curr] + child.se)
			{
				s.erase({dis[child.fi], child.fi});
				dis[child.fi] = dis[curr] + child.se;
				s.insert({dis[child.fi], child.fi});
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << i << "--" << dis[i] << endl;
}
void Dijsktra_pq(int src)
{
	vis.resize(n, false);
	dis.resize(n, inf);
	dis[src] = 0; // don't mark it vis here, unlike bfs
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({dis[src], src});
	while (!pq.empty())
	{
		pii curr = pq.top();	pq.pop();
		if (vis[curr.se])
			continue;
		vis[curr.se] = true;
		for (auto child : adj[curr.se])
		{
			if (dis[child.fi] > dis[curr.se] + child.se)
			{
				dis[child.fi] = dis[curr.se] + child.se;
				pq.push({dis[child.fi], child.fi});
			}
		}
	}
	for (int i = 0; i < dis.size(); i++)
	{
		cout << i << "--" << dis[i] << "\n";
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
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	Dijsktra_set(0);
	Dijsktra_pq(0);
	return 0;
}