// https://www.spoj.com/problems/TFRIENDS/
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
int n;
vector<int> adj[101], tadj[101];
vector<int> v;
vector<int> vis;
void dfs(int node)
{
	vis[node] = true;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
	v.pb(node);
}
void dfs2(int node)
{
	vis[node] = true;
	for (auto child : tadj[node])
		if (!vis[child])
			dfs2(child);
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char ch;	cin >> ch;
				if (ch == 'Y')
					adj[i].pb(j), tadj[j].pb(i);
			}
		}
		vis.resize(n, false);
		for (int i = 0; i < n; i++)
			if (!vis[i])
				dfs(i);
		fill(vis.begin(), vis.end(), false);
		int count = 0;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (!vis[v[i]])
			{
				count++;
				dfs2(v[i]);
			}
		}
		cout << count << endl;
		for (int i = 0; i < n; i++)	adj[i].clear(), tadj[i].clear();
		vis.clear();
		v.clear();
	}
	return 0;
}