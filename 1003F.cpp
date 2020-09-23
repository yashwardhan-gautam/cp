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
int a[303], len[303];
map<string, int> m;
int get_id(string s)
{
	if (!m[s])
		m[s] = m.size();
	return m[s];
}
int fail[303];
// prefix function
void get_fail(int a[], int n)
{
	fail[1] = 0;
	for (int i = 1; i < n; i++)
	{
		int p = fail[i];
		while (p and a[p + 1] != a[i + 1])
			p = fail[p];
		fail[i + 1] = p + (a[p + 1] == a[i + 1]);
	}
	//for (int i = 1; i <= n; i++)
	//	cout << fail[i] << " ";
	//cout << endl;
}
// no of occurances of a in b
int match(int a[], int n, int b[], int m)
{
	int res = 0;
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && b[i] != a[j + 1])j = fail[j];
		j += (b[i] == a[j + 1]);
		if (j == n)
			res++, j = 0;
	}
	return res;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	int sum = n - 1;
	for (int i = 1; i <= n; i++)
	{
		string s;	cin >> s;
		a[i] = get_id(s);
		len[i] = s.size();
		sum += len[i];
	}
	int res = sum;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			//cout << i << " " << j << " :";
			get_fail(a + i - 1, j - i + 1);
			int cnt = match(a + i - 1, j - i + 1, a, n);
			if (cnt >= 2)
			{
				int tot = j - i;
				for (int k = i; k <= j; k++)
					tot += len[k] - 1;
				res = min(res, sum - tot * cnt);
			}
		}
	}
	cout << res << endl;
	return 0;
}