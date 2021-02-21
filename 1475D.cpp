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
int solve()
{
	int n, m;	cin >> n >> m;
	vector<int> a, b;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		if (x == 1)
			a.pb(arr[i]);
		else
			b.pb(arr[i]);
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	for (int i = 1; i < a.size(); i++)	a[i] += a[i - 1];
	for (int i = 1; i < b.size(); i++)	b[i] += b[i - 1];
	int ans = INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		int it = lower_bound(b.begin(), b.end(), m - a[i]) - b.begin();
		if (it != b.size() and a[i] + b[it] >= m) ans = min(ans, i + 1 + 2 * (it + 1));
		if (a[i] >= m) ans = min(ans, i + 1);
	}
	for (int i = 0; i < b.size(); i++)
	{
		int it = lower_bound(a.begin(), a.end(), m - b[i]) - a.begin();
		if (it != a.size() and a[it] + b[i] >= m) ans = min(ans, 2 * (i + 1) + it + 1);
		if (b[i] >= m) ans = min(ans, 2 * (i + 1));
	}
	if (ans == INT_MAX) return -1;
	return ans;
}

int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		cout << solve() << endl;
	return 0;
}

// Won't work beacuse of constraint
/*#include<bits/stdc++.h>
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
int n, m;
vector<int> a, b;
vector<vector<int> > dp;
int solve(int index, int mem_freed_so_far)
{
	if (index >= n)
	{
		if (mem_freed_so_far >= m) return 0;
		return INT_MAX;
	}

	if (dp[index][mem_freed_so_far] != -1)
		return dp[index][mem_freed_so_far];

	int op1 = INT_MAX, op2 = INT_MAX;
	// when i delete the application at index i
	// the memory will get freed by a[index] and inconvinence point will get increased by b[index]
	op1 = b[index] + solve(index + 1, mem_freed_so_far + a[index]);
	op2 = solve(index + 1, mem_freed_so_far);
	return dp[index][mem_freed_so_far] = min(op1, op2);
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		a.resize(n), b.resize(n);
		int sum = 0;
		for (int i = 0; i < n; i++)	cin >> a[i], sum += a[i];
		for (int i = 0; i < n; i++)	cin >> b[i];
		dp.resize(n, vector<int> (sum, -1));
		int ans = solve(0, 0);
		if (ans == INT_MAX)
			cout << "-1\n";
		else
			cout << ans << endl;
		dp.clear();
	}
	return 0;
}*/