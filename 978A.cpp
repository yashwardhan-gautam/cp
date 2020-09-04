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
#define endl			"\n"
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
	vector<int> arr(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	unordered_set<int> s;
	vector<int> res;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.find(arr[i]) == s.end())
		{
			s.insert(arr[i]);
			res.insert(res.begin(), arr[i]);
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";	cout << endl;
	return 0;
}