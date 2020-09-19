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
	int n, k;	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int l = 0, r = n - 1;
	int ans = 0;
	while (l <= r)
	{
		if (l < n and v[l] <= k)
		{
			ans++;
			l++;
		}
		else if (r >= 0 and v[r] <= k)
		{
			ans++;
			r--;
		}
		if (l<n and v[l]>k and r >= 0 and v[r] > k)
			break;
	}
	cout << ans << endl;
	return 0;
}