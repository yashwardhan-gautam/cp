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
bool compare1(pair<char, int> a, pair<char, int> b)
{
	if (a.fi == b.fi)
		return a.se < b.se;
	return a.fi < b.fi;
}
bool compare2(pair<char, int> a, pair<char, int> b)
{
	return a.se < b.se;
}
int32_t main()
{
	fast();
	int n, k;	cin >> n >> k;
	string s;	cin >> s;
	vector<pair<char, int> > v(s.size());
	for (int i = 0; i < s.size(); i++)
		v[i].fi = s[i], v[i].se = i;
	sort(v.begin(), v.end(), compare1);
	v.erase(v.begin(), v.begin() + k);
	sort(v.begin(), v.end(), compare2);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].fi;
	return 0;
}