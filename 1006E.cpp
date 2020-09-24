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
vector<int> adj[200005];
int sz[200005] = {0};
vector<int> v;
int dfs(int node, int parent)
{
	//cout << node << "\n";
	v.pb(node);
	int size = 1;
	for (auto child : adj[node])
		if (child != parent)
			size += dfs(child, node);
	return sz[node] = size ;
}
int32_t main()
{
	fast();
	int n, q;		cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		int t;	cin >> t;
		//cout << t << "->" << i << endl;
		adj[t].pb(i);
	}
	dfs(1, -1);
	unordered_map<int, int> m1;
	//cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		m1[v[i]] = i;
	while (q--)
	{
		int u, k;
		cin >> u >> k;
		if (k == 1)
		{
			cout << u << endl;
			continue;
		}
		if (k > sz[u])
		{
			cout << "-1\n";
			continue;
		}
		cout << v[m1[u] + k - 1] << endl;
	}
	return 0;
}