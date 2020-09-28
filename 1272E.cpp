// https://codeforces.com/problemset/problem/1272/E
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
vector<int> a;
vector<vector<int> > adj;
vector<int> even, odd;
vector<int> ans;
void bfs(vector<int> start, vector<int> end)
{
	vector<int> d(n, inf);
	queue<int> q;
	for (auto v : start) {
		d[v] = 0;
		q.push(v);
	}
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (auto child : adj[curr])
		{
			if (d[child] == inf)
			{
				q.push(child);
				d[child] = d[curr] + 1;
			}
		}
	}
	for (auto v : end)
	{
		if (d[v] != inf)
			ans[v] = d[v];
	}
}
int32_t main()
{
	fast();
	cin >> n;
	a.resize(n);
	adj.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] & 1)
			odd.pb(i);
		else
			even.pb(i);
	}
	for (int i = 0; i < n; i++)
	{
		int left = i - a[i];
		int right = i + a[i];
		if (left >= 0)
			adj[left].pb(i);
		if (right < n)
			adj[right].pb(i);
	}
	ans.resize(n, -1);
	bfs(odd, even);
	bfs(even, odd);
	for (auto it : ans)
		cout << it << " ";
	cout << endl;
	return 0;
}