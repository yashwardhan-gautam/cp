#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 3e4 + 5;
const int mod = 1e9 + 7;
int spf[N];
void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (int i = 4; i < N; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int getfct(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret.size();
}

int *st;
int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = ss + (se - ss) / 2;
    return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                 findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

int findRangeGcd(int ss, int se, int arr[], int n)
{
    return findGcd(0, n - 1, ss, se, 0);
}

int constructST(int arr[], int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                   constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *S_tree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    return st;
}
void solve()
{
    int n, q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> q;
    S_tree(a, n);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int x = findRangeGcd(l, r, a, n);
        int p = getfct(x);
        cout << p << '\n';
    }
}
int32_t main()
{

    fast();
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}