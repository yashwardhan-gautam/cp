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

int32_t main()
{
	fast();
	int n, m, k;	cin >> n >> m >> k;
	vector<int> a(n + 1, 0);
	for (int i = 0; i < n; i++)	cin >> a[i];
	int b[m][3];
	for (int i = 0; i < m; i++)
		cin >> b[i][0] >> b[i][1] >> b[i][2];
	int c[k][2];
	for (int i = 0; i < k; i++)
		cin >> c[i][0] >> c[i][1];
	for (int i = 0; i < m; i++)
		b[i][0]--, b[i][1]--;
	for (int i = 0; i < k; i++)
		c[i][0]--, c[i][1]--;
	vector<int> v(m + 1, 0);
	for (int i = 0; i < k; i++)
	{
		v[c[i][0]] += 1;
		v[c[i][1] + 1] -= 1;
	}
	for (int i = 1; i <= m; i++)
		v[i] += v[i - 1];
	for (int i = 0; i < m; i++)
		b[i][2] *= v[i];
	vector<int> v1(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		//cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;
		v1[b[i][0]] += b[i][2];
		v1[b[i][1] + 1] -= b[i][2];
	}
	for (int i = 1; i <= n; i++)
		v1[i] += v1[i - 1];
	//for (int i = 0; i < n; i++)	cout << v1[i] << " ";	cout << endl;
	for (int i = 0; i < n; i++)	cout << a[i] + v1[i] << " ";
	return 0;
}