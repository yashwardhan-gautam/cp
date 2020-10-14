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
int solve(vector<int> &A, int B)
{
	int res = 0;
	int n = A.size();
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = i + B - 1; j >= i - B + 1; j--)
		{
			if (j >= 0 and j < n and A[j] == 1)
			{
				flag = 1;
				i = j + B - 1;
				res++;
				break;
			}
		}
		if (flag == 0)return -1;
	}
	return res;
}
int32_t main()
{
	fast();
	int n, b;
	vector<int> v;
	cin >> n >> b;
	v.resize(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	cout << solve(v, b) << endl;
	return 0;
}