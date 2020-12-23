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
void build(int s, int e, int node)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return ;
	}
	int mid = (s + e) >> 1;
	// if the tree was build using 1 based indexing
	// the call on left and right will be 2*node,2*node+1 respectively.
	build(s, mid, 2 * node + 1);
	build(mid + 1, e, 2 * node + 2);

	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
// Finds the sum of elements in range qs to qe
int query(int s, int e, int node, int qs, int qe)
{
	// NO OVERLAP[when the range of node does not overlap with the query]
	// ******* --------  *******  (- is query, * is segment range)
	// s     e qs    qe  s     e
	if (s > e or e<qs or s>qe)
		return 0;
	// COMPLETE OVERLAP
	// --------- (qs to qe)
	//   *****   (s to e)  [when range of node is completely inside query]
	if (s >= qs and e <= qe)
		return tree[node];
	// PARTIAL OVERLAP
	// -------         --------- (l to r)
	// 	 ******** 	*******      (s to e) [when the range of node is partially inside the query]
	int mid = (s + e) >> 1;
	return query(s, mid, 2 * node + 1, qs, qe) + query(mid + 1, e, 2 * node + 2, qs, qe);
}
// Point Update
void update(int s, int e, int node, int index, int val)
{
	// finding the index
	if (s == e)
	{
		arr[index] = val;
		tree[node] = val;
		return ;
	}
	int mid = (s + e) >> 1;
	// if the index is on left
	if (index <= mid)
		update(s, mid, 2 * node + 1, index, val);
	// if the index is on right
	else
		update(mid + 1, e, 2 * node + 2, index, val);

	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	arr.resize(n);
	tree.resize(4 * n + 1);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	build(0, n - 1, 0);
	cout << tree[0] << endl;
	update(0, n - 1, 0, 0, 2);
	cout << query(0, n - 1, 0, 0, 3) << endl;
	return 0;
}