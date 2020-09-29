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
}
int n, k, s;
unordered_map<pii, bool> m;
bool solve(int k, int sum, vector<int> &v)
{
	if (k == 0 and sum == 0)
		return true;
	if (k <= 0 or sum <= 0)
		return false;
	if (m.find({k, sum}) != m.end())
		return m[ {k.sum}];
	for (int i = 1; i <= n; i++)
	{
		if (v.back() != i)
		{
			v.pb(i);
			if (solve(k - 1, sum - (abs(v[v.size() - 1] - v[v.size() - 2])), v))
				return m[ {k, sum}] = 1;
			v.pop_back();
		}
	}
	return m[ {k, sum}] = 0;
}
int32_t main()
{
	fast();
	cin >> n >> k >> s;
	vector<int> v;
	v.pb(1);
	dp.resize(k + 1, vector<int> (s + 1, -1));
	if (solve(k, s, v))
	{
		cout << "YES\n";
		for (int i = 1; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}