// https://toph.co/p/traveling-policy-of-ajobdesh
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
int n, m, c, q;
vector<int> adj[10000], tadj[10000];
vector<int> city_to_c(10000);
vector<int> c_to_city(10000);
vector<bool> vis(10000);
void bfs()
{
	for (int i = 0; i < n; i++)
		vis[i] = false;
	c_to_city[c] = 0;
	vis[c] = true;
	queue<int> q;
	q.push(c);
	while (!q.empty())
	{
		int curr = q.front();	q.pop();
		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				vis[child];
				c_to_city[child] = c_to_city[curr] + 1;
				q.push(child);
			}
		}
	}
}
void bfs2()
{
	for (int i = 0; i < n; i++)
		vis[i] = false;
	city_to_c[c] = 0;
	vis[c] = true;
	queue<int> q;
	q.push(c);
	while (!q.empty())
	{
		int curr = q.front();	q.pop();
		for (auto child : tadj[curr])
		{
			if (!vis[child])
			{
				vis[child];
				city_to_c[child] = city_to_c[curr] + 1;
				q.push(child);
			}
		}
	}
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	int cnt = 1;
	while (test--)
	{
		cin >> n >> m >> c >> q;
		for (int i = 0; i < m; i++)
		{
			int u, v;	cin >> u >> v;
			adj[u].pb(v);
			tadj[v].pb(u);
		}
		for (int i = 0; i < n; i++)
			c_to_city[i] = -1, city_to_c[i] = -1;
		bfs();
		bfs2();
		cout << "Case " << cnt << ":\n";
		for (int i = 0; i < q; i++)
		{
			int a, b;	cin >> a >> b;
			if (city_to_c[a] != -1 and c_to_city[b] != -1)
				cout << "The shortest distance from " << a << " to " << b << " is " << city_to_c[a] + c_to_city[b] << ".\n";
			else
				cout << "Not possible to go from " << a << " to " << b << ".\n";
		}
		for (int i = 0; i < n; i++)
			adj[i].clear(), tadj[i].clear();
	}
	return 0;
}