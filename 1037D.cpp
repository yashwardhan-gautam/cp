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
}
int n;
vector<vector<int> > adj;
vector<int> a, b;
bool compare(int x, int y)
{
	return b[x] < b[y];
}
vector<int> bfs(int s)
{
	vector<bool> vis(n + 1, false);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	vector<int> t;
	while (!q.empty())
	{
		int curr = q.front();	q.pop();
		t.pb(curr);
		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				vis[child] = true;
				q.push(child);
			}
		}
	}
	return t;
}
int32_t main()
{
	fast();
	cin >> n;
	adj.resize(n + 1), a.resize(n), b.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end(), compare);
	vector<int> temp = bfs(1);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != temp[i])
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}