#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fi first
#define se second
#define vll vector<int>
#define pii pair<int,ll>
#define pb push_back
#define sz(v) (int)(v).size()
#define inf 1e18
#define md (int)(1e9+7)
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

#define M 100010

#define K 21
int lg[M], st[M][K];
int a[M], b[M], p[M], n, k;
void build() {
	rep(i, 0, n)cin >> b[i];
	rep(i, 0, n)st[i][0] = b[i];
	rep(j, 1, K)rep(i, 0, n - (1 << j) + 1)
	st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int get(int l, int r) {
	int j = lg[r - l + 1];
	return max(st[l][j], st[r - (1 << j) + 1][j]);
}
int get1(int l, int r) {
	int ans = a[r];
	if (l)ans -= a[l - 1];
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	rep(i, 2, M)lg[i] = lg[i / 2] + 1;
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		rep(i, 0, n)cin >> a[i];
		rep(i, 1, n)a[i] += a[i - 1];
		build();
		int mx = 0;
		rep(i, 0, n) {
			int lo = i, hi = n - 1, mid, ans;
			while (lo <= hi) {
				mid = (lo + hi) >> 1;
				int cost = get(i, mid) + (mid - i + 1) * get1(i, mid);
				if (cost > k)hi = mid - 1, ans = mid - 1;
				else lo = mid + 1, ans = mid;
			}
			mx = max(mx, ans - i + 1);
		}
		cout << mx << "\n";
	}
	return 0;
}