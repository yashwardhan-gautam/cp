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
set<vector<int> > st;
void solve(vector<int> &A, int n, int start)
{
	if (start > 1)
	{
		int temp = sqrt(A[start - 1] + A[start - 2]);
		if (A[start - 1] + A[start - 2] != temp * temp)
			return ;
	}
	if (start == n)
	{
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";	cout << endl;
		st.insert(A);
		return ;
	}
	for (int j = start; j < A.size(); j++)
	{
		if (start == j or A[start] != A[j])
		{
			swap(A[start], A[j]);
			solve(A, n, start + 1);
			swap(A[start], A[j]);
		}
	}

}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)	cin >> A[i];
	sort(A.begin(), A.end());
	solve(A, n, 0);
	cout << st.size();
	return 0;
}
