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
const int N = 2e5 + 10;
vector<vector<int> > dv;
void pre()
{
	dv.resize(N);
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			dv[j].pb(i);
}
int32_t main()
{
	fast();
	pre();
	int test;	cin >> test;
	while (test--)
	{
		int n;	cin >> n;
		vi v(n);
		for (int i = 0; i < n; i++)	cin >> v[i];
		vi count(N, 0);
		for (int i = 0; i < n; i++)	count[v[i]]++;
		vi res(N, 0);
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			for (auto j : dv[i])
				res[i] = max(res[i], res[j]);
			res[i] += count[i];
			ans = max(ans, res[i]);
		}
		cout << v.size() - ans << endl;
	}
	return 0;
}