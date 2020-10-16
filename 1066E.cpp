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
#define mod             998244353
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
int v[200005];
int expo(int x, int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1)
			res = (res * x * 1LL) % mod;
		y = y >> 1;
		x = (1LL * x * x) % mod;
	}
	return res % mod;
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	string s1, s2;	cin >> s1 >> s2;

	while (n < m)
		s1 = '0' + s1, n++;
	while (m < n)
		s2 = '0' + s2, m++;
	//cout << s1 << "\n" << s2 << endl;
	for (int i = 0; i < s2.size(); i++)
	{
		v[i] = (s2[i] == '1');
		if (i)
			v[i] += v[i - 1];
	}
	//for (int i = 0; i < v.size(); i++)
	//	cout << v[i] << " ";
	int ans = 0;
	n = s1.size();
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '1')
			ans = (ans + (v[i] * expo(2, n - 1 - i)) % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}