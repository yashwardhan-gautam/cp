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
int n, m, k;
vi v;
int32_t main()
{
	fast();
	cin >> n >> m >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int i;
	int space = k;
	for (i = n - 1; i >= 0; i--)
	{
		if (space >= v[i])
			space -= v[i];
		else
		{
			if (m == 1)
				break;
			m--;
			space = k - v[i];
		}
	}
	cout << n - 1 - i << endl;
	return 0;
}