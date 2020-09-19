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

#define mx 100003
vector<int>v[mx];
int dp[mx];
bool prime[mx];
void sieve ()
{
	memset(prime, true, sizeof(prime));

	for (int p = 2; p <= mx; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			v[p].push_back(p);
			for (int i = 2 * p; i <= mx; i += p) {
				prime[i] = false;
				v[i].push_back(p);// take all number's prime_factors
			}
		}
	}
}

int32_t main()
{
	sieve();
	fast();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int len = 1;
		int num = arr[i];
		//cout << num << " :";
		for (int j = 0; j < v[num].size(); j++)
		{
			int prime_factor = v[num][j];
			//cout << prime_factor << " ";
			len = max(len, dp[prime_factor] + 1); // dp[prime_factor] states how much longest sequence of numbers ending with arr[i] i.e. num  which has a prime_factor is v[num][j] i.e. prime_factor
		}
		//cout << "(" << len << "), ";
		ans = max(ans, len);
		for (int j = 0; j < v[num].size(); j++)
		{
			int prime_factor = v[num][j];
			dp[prime_factor] = max(dp[prime_factor], len );
			//cout << dp[prime_factor] << " ";
		}
		//cout << endl;
	}
	cout << ans;
}
