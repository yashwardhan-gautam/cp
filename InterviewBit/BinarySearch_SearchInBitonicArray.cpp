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
int asc(vector<int> A, int low, int high, int B)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (A[mid] == B)
			return mid;
		else if (A[mid] > B)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

// Function for binary search in descending part of array
int dsc(vector<int>A, int low, int high, int B)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (A[mid] == B)
			return mid;
		else if (A[mid] < B)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int solve(vector<int> &A, int B) {
	int ans = -1;
	int start = 0, end = A.size() - 1;
	int mid = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1])
			break;
		else if (A[mid] < A[mid + 1] && A[mid - 1] < A[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	if (A[mid] == B)
		return mid;
	int l = asc(A, 0, mid - 1, B);
	int r = dsc(A, mid + 1, A.size() - 1, B);
	if (l != -1 || r != -1)
		return l != -1 ? l : r;
	return -1;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	int r;	cin >> r;
	cout << solve(v, r) << endl;
	return 0;
}