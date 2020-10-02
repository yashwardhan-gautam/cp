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
int n, m, x, q;
int n2h[100005], h2n[100005];
vector<pii> adj[100005], tadj[100005];
void H2N()
{
	fill(h2n, h2n + n, inf);
	h2n[x] = 0;
	vector<bool> vis(n, false);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({h2n[x], x});
	while (!pq.empty())
	{
		pii curr = pq.top();	pq.pop();
		if (vis[curr.se])
			continue;
		vis[curr.se] = true;
		for (auto child : adj[curr.se])
		{
			if (h2n[child.fi] > h2n[curr.se] + child.se)
			{
				h2n[child.fi] = h2n[curr.se] + child.se;
				pq.push({h2n[child.fi], child.fi});
			}
		}
	}
}
void N2H()
{
	fill(n2h, n2h + n, inf);
	n2h[x] = 0;
	vector<bool> vis(n, false);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({n2h[x], x});
	while (!pq.empty())
	{
		pii curr = pq.top();	pq.pop();
		if (vis[curr.se])
			continue;
		vis[curr.se] = true;
		for (auto child : tadj[curr.se])
		{
			if (n2h[child.fi] > n2h[curr.se] + child.se)
			{
				n2h[child.fi] = n2h[curr.se] + child.se;
				pq.push({n2h[child.fi], child.fi});
			}
		}
	}
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	int count = 1;
	while (test--)
	{
		cin >> n >> m >> x >> q;
		x--;
		for (int i = 0; i < m; i++)
		{
			int u, v, w;	cin >> u >> v >> w;
			u--, v--;
			adj[u].pb({v, w});
			tadj[v].pb({u, w});
		}
		H2N();
		N2H();
		cout << "Case " << count << ":\n";
		count++;
		for (int i = 0; i < q; i++)
		{
			int a, b;	cin >> a >> b;
			a--, b--;
			if (n2h[a] == inf or h2n[b] == inf)
				cout << "Be seeing ya, John\n";
			else
				cout << n2h[a] + h2n[b] << "\n";
		}
		for (int i = 0; i < n; i++)
			adj[i].clear(), tadj[i].clear(), n2h[i] = 0, h2n[i] = 0;

	}
	return 0;
}