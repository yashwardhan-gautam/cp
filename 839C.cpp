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
vector<int> adj[100001];
double ans;
void dfs(int node, int parent, double prob, int len)
{
	if (adj[node].size() == 1 and adj[node][0] == parent)
	{
		//cout << node << " " << prob << " " << len << endl;
		ans += (prob * (len));
		return ;
	}
	double new_prob;
	if (node == 1)
		new_prob = (1.0 / (1.0 * adj[node].size()));
	else
		new_prob = (1.0 / (1.0 * (adj[node].size() - 1)));
	for (auto child : adj[node])
		if (child != parent)
			dfs(child, node, prob * new_prob, len + 1);
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans = 0;
	dfs(1, -1, 1, 0);
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}