// https://codeforces.com/contest/988/problem/C
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
struct triplet {
	int sum;
	int seq;
	int idx;
	// sum of sequence seq without element at index 'idx'
};
bool compare(triplet a, triplet b)
{
	return a.sum < b.sum;
}
int32_t main()
{
	fast();
	int k;	cin >> k;
	vector<vector<int> > v(k);
	vector<triplet> t;
	for (int i = 0; i < k; i++)
	{
		int n;	cin >> n;
		v[i].resize(n);
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			sum += v[i][j];
		}
		for (int j = 0; j < n; j++)
			t.push_back({sum - v[i][j], i, j});
	}
	sort(t.begin(), t.end(), compare);
	bool flag = false;
	for (int i = 0; i < t.size() - 1; i++)
	{
		//cout << t[i].sum << " " << t[i].seq << " " << t[i].idx << endl;
		if (t[i].sum == t[i + 1].sum and t[i].seq != t[i + 1].seq)
		{
			cout << "YES\n";
			flag = true;
			cout << t[i].seq + 1 << " " << t[i].idx + 1 << endl;
			cout << t[i + 1].seq + 1 << " " << t[i + 1].idx + 1 << endl;
			break;
		}
	}
	if (!flag)
		cout << "NO\n";
	return 0;
}