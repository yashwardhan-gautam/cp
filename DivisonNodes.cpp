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
vector<vector<int> > ind;
vector<int> arr;
int  total, ans, ans_index;
int dfs(int node)
{
	vis[node] = true;
	int sum = 0;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int v = adj[node][i];
		if (!vis[v])
		{
			int curr = dfs(v);
			int diff = abs(2 * curr - total);
			if (ans == -1 or diff < ans or (diff == ans and ind[node][i] < ans_index))
			{
				ans = diff;
				ans_index = ind[node][i];
			}
			sum += curr;
		}
	}
	return sum + arr[node];
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int n;	cin >> n;
		adj.resize(n), ind.resize(n);
		vis.resize(n, false);
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
			ind[u].pb(i);
			ind[v].pb(i);
		}
		arr.resize(n);
		total = 0;
		for (int  i = 0; i < n; i++)
		{
			cin >> arr[i];
			total += arr[i];
		}
		ans = -1, ans_index = -1;
		dfs(0);
		cout << ans_index + 1;
		adj.clear();
		vis.clear();
		ind.clear();
		arr.clear();
	}
	return 0;
}