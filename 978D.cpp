#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define clr(x) memset(x,0,sizeof(x))
const ll size = 1e6 + 7;
ll arr[size];
void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll check(ll n)
{
    vector<ll> vi;
    for (ll i = 0; i < n; i++)vi.pb(arr[i]);
    ll d = vi[1] - vi[0];
    ll pos = -1;
    for (ll i = 2; i < n; i++)
    {
        if (vi[i] - vi[i - 1] != d)
        {
            if (vi[i] + 1 - vi[i - 1] == d)vi[i] = vi[i] + 1;
            else if (vi[i] - 1 - vi[i - 1] == d)vi[i] = vi[i] - 1;
            else {pos = i; break;}
        }
    }
    if (pos != -1)return INT_MAX;
    else
    {
        ll ans = 0;
        for (ll i = 2; i < n; i++)if (arr[i] != vi[i])ans++;
        return ans;
    }
}
int main()
{
    fast();
    ll n; cin >> n;
    if (n == 1 || n == 2) {cout << 0 << endl; return 0;}
    for (ll i = 0; i < n; i++)cin >> arr[i];
    ll ans = INT_MAX; ll a = arr[0]; ll b = arr[1];
    arr[0] = a + 1; arr[1] = b - 1;
    ans = min(ans, check(n) + 2);
    arr[0] = a - 1; arr[1] = b + 1;
    ans = min(ans, check(n) + 2);
    arr[0] = a + 1; arr[1] = b + 1;
    ans = min(ans, check(n) + 2);
    arr[0] = a - 1; arr[1] = b - 1;
    ans = min(ans, check(n) + 2);
    arr[0] = a; arr[1] = b + 1;
    ans = min(ans, check(n) + 1);
    arr[0] = a; arr[1] = b - 1;
    ans = min(ans, check(n) + 1);
    arr[0] = a + 1; arr[1] = b;
    ans = min(ans, check(n) + 1);
    arr[0] = a - 1; arr[1] = b;
    ans = min(ans, check(n) + 1);
    arr[0] = a; arr[1] = b;
    ans = min(ans, check(n));
    if (ans == INT_MAX)cout << -1 << endl;
    else cout << ans << endl;
}