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
	int n;	cin >> n;
	int ans = 0;
	string a, b;	cin >> n >> a >> b;
	for (int i = 0; i < n / 2; i++)
	{
		map<char, int> m;
		if (b[i] == b[n - 1 - i])
		{
			if (a[i] != a[n - 1 - i])
				ans++;
		}
		else
		{
			map<char, int> m;
			m[b[i]]++;
			m[b[n - 1 - i]]++;
			m[a[i]]--;
			m[a[n - 1 - i]]--;
			for (auto it : m)
				ans += (it.second > 0) ? it.second : 0;
		}
	}
	if (n % 2)
		if (a[n / 2] != b[n / 2])
			ans++;
	cout << ans;
	return 0;
}