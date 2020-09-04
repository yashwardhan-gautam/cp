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
int n;
string s;
int32_t main()
{
	fast();
	cin >> n >> s;
	unordered_map<string, int> m;
	for (int i = 0; i < n - 1; i++)
	{
		m[s.substr(i, 2)]++;
	}
	int ans = INT_MIN;
	string sans;
	for (auto it : m)
	{
		if (it.second > ans)
		{
			ans = it.second;
			sans = it.first;
		}
	}
	cout << sans << endl;
	return 0;
}