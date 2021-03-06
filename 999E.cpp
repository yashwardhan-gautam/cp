// https://codeforces.com/contest/999/problem/E
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
int n, m, s, cnt;
vector<int> adj[5050];
int final_vis[5050];
int vis[5050];
void dfs1(int s)
{
	final_vis[s] = true;
	for (int i = 0; i < adj[s].size(); i++)
		if (!final_vis[adj[s][i]])
			dfs1(adj[s][i]);
}
void dfs2(int s)
{
	vis[s] = true;
	cnt++;
	for (auto child : adj[s])
		if (!vis[child] and !final_vis[child])
			dfs2(child);
}
int32_t main()
{
	fast();
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
	}
	dfs1(s);
	vector<pii> v;
	for (int i = 1; i <= n; i++)
	{
		if (!final_vis[i])
		{
			cnt = 0;
			memset(vis, false, sizeof(vis));
			dfs2(i);
			v.pb({cnt, i});
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0;
	for (auto it : v)
	{
		if (!final_vis[it.se])
		{
			ans++;
			dfs1(it.se);
		}
	}
	cout << ans << endl;
	return 0;
}