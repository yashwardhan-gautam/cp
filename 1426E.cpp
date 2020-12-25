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
int solve(vector<int> a , vector<int> b)
{
	int ans = 0;
	ans += min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	return ans;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> a(3), b(3);
	for (int i = 0; i < 3; i++)	cin >> a[i];
	for (int i = 0; i < 3; i++)	cin >> b[i];
	int t1 = a[0] - b[0] - b[2];
	int t2 = a[1] - b[1] - b[0];
	int t3 = a[2] - b[2] - b[1];
	int mi = 0;
	mi = max(mi, max(t1, max(t2, t3)));
	cout << mi << " ";
	cout << solve(a, b) << endl;
	return 0;
}