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
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			int lx = v[i] - (1 << j);
			int rx = v[i] + (1 << j);
			bool isl = binary_search(v.begin(), v.end(), lx);
			bool isr = binary_search(v.begin(), v.end(), rx);
			if (isl and isr and res.size() < 3)
			{
				res = {lx, v[i], rx};
			}
			if (isl and res.size() < 2)
			{
				res = {lx, v[i]};
			}
			if (isr and res.size() < 2)
			{
				res = {v[i], rx};
			}
		}
	}
	if (res.size() == 0)
		cout << 1 << "\n" << v[0] << "\n";
	else
	{
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}