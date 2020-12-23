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
#define ll int
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
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		if (n == 1) {
			cout << 0 << endl;
		}
		else {
			ll ans = n + 1;
			int t;
			for (ll i = 1; i <= 100000; i++) {
				if (i + (n - 1) / (i + 1) < ans)
				{
					ans = i + (n - 1) / (i + 1);
					t = i;
				}
				//ans = min(ans, i + (n - 1) / (i + 1));
			}
			cout << t << " " << ans << endl;
		}
	}
	return 0;
}