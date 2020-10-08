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

int solve(vector<int> &A)
{
	int ans = 0;
	int n = A.size();
	vector<int> right(n, 0);
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], A[i + 1]);
	for (int i = 0; i < n; i++)	cout << right[i] << " ";	cout << endl;
	set<int> s;
	s.insert(A[0]);
	for (int i = 1; i < n - 1; i++)
	{
		s.insert(A[i]);
		auto itr = s.find(A[i]);
		ans = max(ans, (A[i] + (*(--itr)) + right[i]));
	}
	return ans;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)	cin >> A[i];
	cout << solve(A) << endl;
	return 0;
}