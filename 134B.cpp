/*
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

int solve(int a, int b, int n)
{
	if (a > n or b > n)
	{
		//cout << a << " " << b << " ";
		//cout << "0\n";
		return INT_MAX;
	}
	if (a == n or b == n)
	{
		//cout << a << " " << b << " ";
		//cout << "1\n";
		return 1;
	}
	int ans = min(solve(a, a + b, n), solve(a + b, b, n)) + 1;
	//cout << a << " " << b << " ";
	//cout << ans << endl;
	return ans;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	cout << solve(1, 1, n) - 1 << endl;
	return 0;
}
*/
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

int ans = INT_MAX;

void Fun(int a, int b, int cnt) {
	// base case
	if (a == 1 && b == 1) ans = min(ans, cnt);

	if (a - b > 0) Fun(a - b, b, cnt + 1);
	if (b - a > 0) Fun(a, b - a, cnt + 1);
}

void Pairs(int n) {
	if (n == 1) {cout << 0 << endl; return;}
	for (int x = 1; x < n; x++) {
		Fun(x, n - x, 1);
	}
	cout << ans << endl;
}

int32_t main() {
	int n;
	cin >> n;
	Pairs(n);
	return 0;
}



