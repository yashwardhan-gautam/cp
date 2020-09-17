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
int n, m;
int solve()
{
	cin >> n >> m;
	vector<int> d(10001, -1);
	queue<int> q;
	d[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int curr = q.front();
		//cout << curr << endl;
		q.pop();
		if (d[m] != -1)
			return d[m];
		if (2 * curr > 0 and 2 * curr <= d.size() and d[2 * curr] == -1)
		{
			q.push(2 * curr);
			d[2 * curr] = d[curr] + 1;
		}
		if (curr - 1 > 0 and curr - 1 <= d.size() and d[curr - 1] == -1)
		{
			q.push(curr - 1);
			d[curr - 1] = d[curr] + 1;
		}
	}
	return d[m];
}
int32_t main()
{
	fast();
	cout << solve() << endl;
	return 0;
}