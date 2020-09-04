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
vector<int> v;
int32_t main()
{
	fast();
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)	cin >> v[i];

	map<int, int> dp;
	int ma = 0;
	int val = 0;
	for (int i = 0; i < v.size(); i++)
	{
		dp[v[i]] = dp[v[i] - 1] + 1;
		if (ma < dp[v[i]])
		{
			ma = dp[v[i]];
			val = v[i];
		}
	}
	vector<int> res;
	for (int i = n - 1; i >= 0; i--)
	{
		if (dp[v[i]] == ma and v[i] == val)
		{
			res.pb(i + 1);
			ma--, val--;
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[res.size() - 1 - i] << " ";
	return 0;
}

// https://codeforces.com/blog/entry/50626
// https://codeforces.com/blog/entry/21853
// https://codeforces.com/contest/776/submission/24950229
