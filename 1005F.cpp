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
int n, m, k;
vector<int> adj[200005];
vector<string> ans;
vector<vector<int> > inc;
void solve(int index, string &s)
{
	if (index > n)
	{
		//cout << s << endl;
		if (k)
		{
			ans.pb(s);
			k--;
		}
		return ;
	}
	for (int j = 0; j < inc[index].size(); j++)
	{
		s[inc[index][j]] = '1';
		if (k)
			solve(index + 1, s);
		s[inc[index][j]] = '0';
	}
}
int32_t main()
{
	fast();
	cin >> n >> m >> k;
	vector<pii> edges;
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		edges.pb({u, v});
		adj[u].pb(v);
		adj[v].pb(u);
	}
	queue<int> q;
	vector<bool> vis(n + 1, false);
	vector<int> dis(n + 1);
	vis[1] = true;
	q.push(1);
	dis[1] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				dis[child] = dis[curr] + 1;
				vis[child] = true;
				q.push(child);
			}
		}
	}
	inc.resize(n + 1);
	for (int e = 0; e < edges.size(); e++)
	{
		if (dis[edges[e].fi] + 1 == dis[edges[e].se])
			inc[edges[e].se].pb(e);
		else if (dis[edges[e].se] + 1 == dis[edges[e].fi])
			inc[edges[e].fi].pb(e);
	}
	/*for (int i = 0; i < inc.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < inc[i].size(); j++)
			cout << inc[i][j] << " ";
		cout << endl;
	}*/
	string b;
	for (int i = 0; i < m; i++)
		b.pb('0');
	solve(2, b);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}