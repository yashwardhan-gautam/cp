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
void solve()
{
	int n, k, l;
	cin >> n >> k >> l;
	if (k * l < n or (n >= 2 and k == 1))
	{
		cout << "-1\n";
		return ;
	}
	vector<int> v;
	int bowled[k] = {0};
	int curr = 0;
	for (int i = 1; i <= n; i++)
	{
		//cout << curr << " " << bowled[curr] << endl;
		if (bowled[curr] < l)
		{
			v.pb(curr);
			bowled[curr]++;
		}
		curr = (curr + 1) % k;
	}
	if (v.size() != n or (n >= 2 and k == 1))
	{
		cout << "-1\n";
		return ;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] + 1 << " ";
	cout << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		solve();
	}
	return 0;
}