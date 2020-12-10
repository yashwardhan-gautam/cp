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
void print(vector<int> arr)
{
	for (auto it : arr) cout << it << " ";
	cout << endl;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 and arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		print(arr);
	}
	return 0;
}