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

int ans = 0;
bitset<30> col, rd, ld;
void NQueen(int i,  int n)
{
	if (i == n)
	{
		ans++;
		return ;
	}
	for (int j = 0; j < n; j++)
	{
		if (!col[j] and !rd[i + j] and !ld[j - i + n - 1])
		{
			col[j] = rd[i + j] = ld[j - i + n - 1] = 1;
			NQueen(i + 1, n);
			col[j] = rd[i + j] = ld[j - i + n - 1] = 0;
		}
	}
}

int32_t main()
{
	fast();
	int n;	cin >> n;
	NQueen(0, n);
	cout << ans << endl;
	return 0;
}
