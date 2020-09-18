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
int n, k;
vector<int> v;
vector<int> adj[100001];
int ans = 0;
void dfs(int node, int parent, int count)
{
	if (v[node])
		count++;
	else
		count = 0;
	//cout << node << " " << count << endl;

	if (count > k)
		return ;
	if (adj[node].size() == 1 and adj[node][0] == parent and count <= k)
	{
		ans++;
		return ;
	}
	for (auto child : adj[node])
		if (child != parent)
			dfs(child, node, count);
}
int32_t main()
{
	fast();
	cin >> n >> k;
	v.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)	cin >> v[i];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int count = 0;
	dfs(1, -1, count);
	cout << ans << endl;
	return 0;
}