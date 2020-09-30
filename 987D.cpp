// https://codeforces.com/problemset/problem/987/D
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
int n, m, k, s;
vector<vector<int> > goods, adj;
vector<vector<int> > dis;
void bfs(vector<int> v, int good_number)
{
	vector<int> vis(n, false);
	queue<int> q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
		vis[v[i]] = true;
		dis[v[i]][good_number] = 0;
	}
	while (!q.empty())
	{
		int curr = q.front();	q.pop();
		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				vis[child] = true;
				dis[child][good_number] = dis[curr][good_number] + 1;
				q.push(child);
			}
		}
	}
}
int32_t main()
{
	fast();
	cin >> n >> m >> k >> s;
	goods.resize(k);
	adj.resize(n);
	dis.resize(n, vector<int> (k));
	for (int i = 0; i < n; i++)
	{
		int t;	cin >> t;
		goods[t - 1].pb(i);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < goods.size(); i++)
		bfs(goods[i], i);
	for (int i = 0; i < n; i++)
	{
		sort(dis[i].begin(), dis[i].end());
		int sum = 0;
		for (int j = 0; j < s; j++)
			sum += dis[i][j];
		cout << sum << " ";
	}
	cout << endl;
	return 0;
}