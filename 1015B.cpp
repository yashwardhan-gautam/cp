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
void solve(string s, string t)
{
	int i = 0, j = 0;
	vector<int> v;
	int n = s.size();
	while (i < s.size())
	{
		if (s[i] != t[i])
		{
			int ii = i;
			int jj = i;
			for (int k = i; k < n; k++)
			{
				if (t[i] == s[k])
				{
					jj = k;
					break;
				}
			}
			for (int k = jj - 1; k >= i; k--)
			{
				v.pb(k);
				swap(s[k], s[k + 1]);
			}
		}
		i++;
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] + 1 << " ";	cout << endl;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	string s, t;	cin >> s >> t;
	string s1 = s, t1 = t;
	sort(s1.begin(), s1.end());
	sort(t1.begin(), t1.end());
	if (s1 != t1)
	{
		cout << "-1\n";
		return 0;
	}
	if (s == t)
	{
		cout << "0\n";
		return 0;
	}
	solve(s, t);
	return 0;
}