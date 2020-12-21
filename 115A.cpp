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
vector<bool> vis;
int ans = 0;
int dfs(int node)
{
	int temp_ans = 0;
	vis[node] = true;
	for (auto child : adj[node])
	{
		if (!vis[child])
		{
			temp_ans = max(temp_ans, dfs(child));
		}
	}
	return temp_ans + 1;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	adj.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		int p;	cin >> p;
		if (p != -1)
			adj[p].pb(i);
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(vis.begin(), vis.end(), false);
		ans = max(ans, dfs(i));
	}
	cout << ans;
	return 0;
}