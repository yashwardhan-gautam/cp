#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
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
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;
int a[200001];
vi adj[200001];
int dp1[200001];
int dp2[200001];

void dfs1(int nd = 1, int pr = 0)
{
	dp1[nd] = a[nd] == 1 ? 1 : -1;

	for (auto ch : adj[nd])
	{
		if (ch == pr)
			continue;

		dfs1(ch, nd);
		dp1[nd] += max(0ll, dp1[ch]);
	}
}

void dfs2(int nd = 1, int pr = 0)
{
	dp2[nd] = dp1[nd];

	if (pr)
	{
		int val = dp2[pr] - max(0ll, dp1[nd]);
		dp2[nd] += max(0ll, val);
	}

	for (auto ch : adj[nd])
	{
		if (ch == pr)
			continue;

		dfs2(ch, nd);
	}
}

int32_t main()
{
	c_p_c();
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs1();
	dfs2();
	for(int i=1;i<=n;i++)	cout<<a[i]<<" ";	cout<<endl;
	for (int i = 1; i <= n; ++i)
		cout << dp2[i] << ' ';

	return 0;
}
