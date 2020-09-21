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

int32_t main()
{
	fast();
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
	double ans = 0;
	for (int len = k - 1; len <= n; len++)
	{
		for (int start = 0; start + len < n; start++)
		{
			int y = start + len;
			double tans = 0;
			if (start == 0)
				tans += (a[y]);
			else
				tans += (a[y] - a[start - 1]);
			tans = (tans * 1.0) / (y - start + 1);
			//cout << start << " " << y << " " << tans << endl;
			ans = max(ans, tans);
		}
	}
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}