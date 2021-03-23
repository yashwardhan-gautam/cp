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
vector<vector<int> > adj;
vector<int> deg;
vector<bool> vis;
vector<pair<int, int> > wet;
vector<pair<int, int> > dry;
vector<int> w;
int sz = 0, eg = 0;
void dfs(int node)
{
	sz++;
	vis[node] = 1;
	eg += deg[node];
	for (auto child : adj[node])
	{
		if (!vis[child])
		{
			vis[child] = 1;
			dfs(child);
		}
	}
}
int32_t main()
{
	fast();
	int n, m, k;	cin >> n >> m >> k;
	adj.resize(n + 1);
	deg.resize(n + 1, 0);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	w.resize(k);
	for (int i = 0; i < k; i++)	cin >> w[i];
	int maxsz = 0, ans1 = 0, ans2 = 0;
	for (int i = 0; i < k; i++)
	{
		sz = 0, eg = 0;
		if (vis[w[i]])
			continue;
		dfs(w[i]);
		maxsz = max(maxsz, sz);
		eg /= 2;
		wet.pb({sz, eg});
		ans1 += (sz * (sz - 1)) / 2 - eg;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			sz = 0;
			eg = 0;
			dfs(i);
			eg /= 2;
			dry.pb({sz, eg});
			ans1 += (sz * (sz - 1)) / 2 - eg;
		}
	}
	sort(wet.begin(), wet.end());
	int pre = 0, curr = 0;
	for (int i = 0; i < dry.size(); i++)
	{
		ans2 += pre * dry[i].fi;
		ans1 += pre * dry[i].fi;
		pre += dry[i].fi;
	}
	ans2 += pre * maxsz;
	ans1 += pre * maxsz;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}