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
	int n, m;	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	map<int, int> c;
	bool has = false;
	c[0] = 1;
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] < m)
			sum--;
		else if (p[i] > m)
			sum++;

		if (p[i] == m)
			has = true;
		if (has)
		{
			//cout << p[i] << " " << c[sum] << " " << c[sum - 1] << endl;
			ans += c[sum] + c[sum - 1];
		}
		else
			c[sum]++;
	}
	cout << ans << endl;
	return 0;
}