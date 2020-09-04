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
vector<int> v;
void dfs(int t, unordered_set<int> &s, vector<int> &v1)
{
	//cout << t << "\n";
	v1.push_back(t);
	s.erase(t);
	if (t % 3 == 0 and s.find(t / 3) != s.end())
	{
		dfs(t / 3, s, v1);
	}
	if (s.find(t * 2) != s.end())
	{
		dfs(2 * t, s, v1);
	}
}
int32_t main()
{
	fast();
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	vector<int> v1;
	for (int i = 0; i <= n - 1; i++)
	{
		unordered_set<int> s(v.begin(), v.end());
		dfs(v[i], s, v1);
		//for (int i = 0; i < v1.size(); i++)	cout << v1[i] << " ";	cout << endl;
		if (v1.size() == n)
			break;
		s.clear();
		v1.clear();
	}
	for (int i = 0; i < v1.size(); i++)	cout << v1[i] << " ";	cout << endl;
	return 0;
}