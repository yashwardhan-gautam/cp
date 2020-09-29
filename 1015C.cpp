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
bool compare(pair<int, int> a, pair<int, int> b)
{
	return (a.fi - a.se) > (b.fi - b.se);
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	int suma = 0, sumb = 0;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].fi >> v[i].se;
		suma += v[i].fi;
		sumb += v[i].se;
	}
	if (suma <= m)
	{
		cout << "0\n";
		return 0;
	}
	if (sumb > m)
	{
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(), v.end(), compare);
	//for (int i = 0; i < v.size(); i++)
	//cout << v[i].fi << " " << v[i].se << endl;
	int count = 0;
	int index = 0;
	while (suma > m)
	{
		//cout << suma << " - " << v[index].fi - v[index].se << endl;
		suma -= (v[index].fi - v[index].se);
		count++;
		index++;
	}
	cout << count << endl;
	return 0;
}