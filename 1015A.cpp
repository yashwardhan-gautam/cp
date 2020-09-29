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
	int n, m;	cin >> n >> m;
	vector<int> v(m + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int a, b;	cin >> a >> b;
		for (int j = a; j <= b; j++)
			v[j]++;
	}
	//for (int i = 1; i <= m; i++)
	//	cout << v[i] << " ";	cout << endl;
	int i = 1;
	vector<int> ans;
	int count = 0;
	while (i <= m)
	{
		while (i <= m and v[i] == 0)
		{
			ans.pb(i);
			count++;
			i++;
		}
		i++;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}