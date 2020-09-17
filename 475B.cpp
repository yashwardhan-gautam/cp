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
vector<int> adj[401];
int vis[401] = {0};
void dfs(int node)
{
	vis[node] = 1;
	for (int j = 0; j < adj[node].size(); j++)
		if (!vis[adj[node][j]])
			dfs(adj[node][j]);
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	string s1, s2;	cin >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '>')
		{
			for (int j = 0; j < m - 1; j++)
				adj[m * i + j].pb(m * i + j + 1);
		}
		else
		{
			for (int j = m - 1; j > 0; j--)
				adj[m * i + j].pb(m * i + j - 1);
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (s2[j] == '^')
		{
			for (int i = n - 1; i > 0; i--)
				adj[i * m + j].pb((i - 1)*m + j);
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
				adj[i * m + j].pb((i + 1)*m + j);
		}
	}
	bool flag = false;
	for (int i = 0; i < n * m; i++)
	{
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for (int j = 0; j < n * m; j++)
		{
			if (!vis[j])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (!flag)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}