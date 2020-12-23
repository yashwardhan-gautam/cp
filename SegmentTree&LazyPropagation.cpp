// Problem : Range Sum
// Query 1. Find Sum of elements in range L to R.
// Query 2. Increase the value of all elements from L to R by a given number.
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
vector<int> arr;
vector<int> tree;
vector<int> lazy;
void build(int s, int e, int node)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return ;
	}
	int mid = (s + e) >> 1;
	build(s, mid, 2 * node + 1);
	build(mid + 1, e, 2 * node + 2);
	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
// update all the elements in range qs to qe by val
void update(int s, int e, int node, int qs, int qe, int val)
{
	if (lazy[node] != 0)
	{
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e)
		{
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (s > e or s > qe or e < qs)
		return ;
	if (s >= qs and e <= qe)
	{
		tree[node] += (e - s + 1) * val; // update the value at current node
		if (s != e)								       // update the lazy value of childs, if it's not a leaf node
		{
			lazy[2 * node + 1] += val;
			lazy[2 * node + 2] += val;
		}
		return ;
	}
	int mid = (s + e) >> 1;
	update(s, mid, 2 * node + 1, qs, qe, val);
	update(mid + 1, e, 2 * node + 2, qs, qe, val);
	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
int query(int s, int e, int node, int qs, int qe)
{
	if (s > e or s > qe or e < qs)
		return 0;
	if (lazy[node] != 0)
	{
		tree[node] += (s - e + 1) * lazy[node];
		if (s != e)
		{
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (s >= qs and e <= qe)
		return tree[node];
	int mid = (s + e) >> 1;
	int left = query(s, mid, 2 * node + 1, qs, qe);
	int right = query(mid + 1, e, 2 * node + 2, qs, qe);
	return (left + right);
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	tree.resize(4 * n + 1, 0);
	lazy.resize(4 * n + 1, 0);
	build(0, n - 1, 0);
	update(0, n - 1, 0, 0, 3, 1);
	cout << query(0, n - 1, 0, 0, 4);
	return 0;
}