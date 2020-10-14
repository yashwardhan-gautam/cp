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
int v[200002];
int32_t main()
{
	fast();
	int q; cin >> q;
	int l = 0, r = 0;
	char ch;	int id;
	cin >> ch >> id;
	v[id] = 0;
	q--;
	while (q--)
	{
		cin >> ch >> id;
		if (ch == 'L')
			v[id] = --l;
		else if (ch == 'R')
			v[id] = ++r;
		else
		{
			//cout << v[id] << " " << (v[id] - l) << " " << r - v[id] << endl;
			cout << min(v[id] - l, r - v[id]) << endl;
		}
	}
	return 0;
}