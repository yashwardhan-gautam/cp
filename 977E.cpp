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
bool cycle(unordered_map<int, vector<int> > &adj, int s, vector<bool> &vis, int n, int m)
{
	vis[s] = true;
	queue<int> q;
	q.push(s);

	bool flag = true;
	if (adj[s].size() != 2)
		flag = false;
	while (!q.empty())
	{
		int u = q.front();	q.pop();
		for (auto v : adj[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);
				if (adj[v].size() != 2)
				{
					flag = false;
				}
			}
		}
	}
	return flag;
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	unordered_map<int, vector<int> > adj;
	for (int i = 0; i < m; i++)
	{
		int x, y;	cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<bool> vis(n + 1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (cycle(adj, i, vis, n, m))
				ans++;
		}
	}
	cout << ans;
	return 0;
}