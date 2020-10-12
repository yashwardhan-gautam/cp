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
#define setbits(x)      __builtin_popcountint(x)
#define zrobits(x)      __builtin_ctzint(x)
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
int n, k;
int a[2001];


bool isPossible(int x) {
	int dp[2001] = {0};
	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i ; j++) {
			if (abs(a[i] - a[j]) <= (i - j)*x) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	int max_transaction = 0;
	for (int i = 0; i < n; i++) {
		max_transaction = max(max_transaction, dp[i]);
	}
	int min_transactions = (n - 1) - max_transaction;
	return min_transactions <= k;
}

int solve() {
	int s = 0;
	int e = 1e12; // wiint work in 40 iterations

	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(mid)) {
			// if mid == 2
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}

int32_t main() {
	fast();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve() << endl;
	return 0;
}





















