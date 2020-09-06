// https://codeforces.com/contest/988/problem/C
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
	int k;	cin >> k;
	vector<vector<pair<int, int> > > v(k);
	for (int i = 0; i < k; i++)
	{
		int n;	cin >> n;
		v[i].resize(n);
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j].first;
			v[i][j].second = j;
			sum += v[i][j].first;
		}
		for (int j = 0; j < n; j++)
			v[i][j].first = sum - v[i][j].first;
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j].first << "," << v[i][j].second << " ";
		cout << endl;
	}
	return 0;
}