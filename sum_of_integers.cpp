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
}
int fun(int a)
{
	int tmp = 0;
	int prev = 0;
	for (int i = 1; i <= a - 2; i++)
	{
		prev = prev + i;
		tmp = tmp + (i * (i + 1)) * a + prev;
	}
	int mx = a * (a - 1) - 1;
	int sum = (mx * (mx + 1)) / 2;
	sum = sum - tmp;
	return (sum % mod);
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a;
		cin >> a;
		cout << fun(a) << endl;
	}
}