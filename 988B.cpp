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
bool compare(string a, string b)
{
	return a.size() < b.size();
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	sort(v.begin(), v.end(), compare);
	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i + 1].find(v[i]) == string::npos)
		{
			flag = false;
			break;
		}
	}
	if (!flag)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << v[i] << endl;
	}
	return 0;
}