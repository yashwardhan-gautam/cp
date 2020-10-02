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
	int n, k;	cin >> n >> k;
	int sum = 0;
	bool flag = true;
	int ans;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		sum += t;
		if (sum < i * k)
		{
			if (flag)
			{
				flag = false;
				ans = i;
			}
		}
	}
	if (flag)
		ans = sum / k + 1 ;
	cout << ans << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}