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
bool possible(vector<int> &A, int mid, int B)
{
	int total = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > mid)
			total += (A[i] - mid);
	}
	return (total >= B);
}
int solve(vector<int> &A, int B) {
	int s = INT_MAX, e = INT_MIN;
	for (int i = 0; i < A.size(); i++)
		s = min(s, A[i]), e = max(e, A[i]);
	int res = 0;
	while (s <= e)
	{
		int mid = (s + e) >> 1;
		if (possible(A, mid, B))
		{
			res = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return res;
}

int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int b;	cin >> b;
	cout << solve(v, b);
	return 0;
}