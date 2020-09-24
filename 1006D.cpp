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

int n, ans = 0;
string a, b;
int solve(int i)
{
	map <char, int> m;
	m[a[i]]++;
	m[a[n - i - 1]]++;
	m[b[i]]++;
	m[b[n - 1 - i]]++;
	if (m.size() == 1)
		return 0;
	if (m.size() == 2)
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			if (it->second == 2)
				return 0;
			else
				return 1;
		}
	}
	if (m.size() == 4)
		return 2;
	if (a[i] == a[n - 1 - i])
		return 2;
	return 1;
}
int32_t main()
{
	fast();
	cin >> n >> a >> b;
	for (int i = 0; i < n / 2; i++)
	{
		ans += solve(i);
	}
	if (n % 2)
		if (a[n / 2] != b[n / 2])
			ans++;
	cout << ans;
	return 0;
}