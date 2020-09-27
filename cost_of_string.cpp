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
#define endl                   "\n"
void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
bool solve(vector<int> &v, int cost, string res)
{
    if (cost == 0)
    {
        cout << res << " ";
        return true;
    }
    for (int i = 25; i >= 0; i--)
    {
        if (v[i] <= cost)
        {
            res += (i + 'a');
            if (solve(v, cost - v[i], res))
                return true;
            res.pop_back();
        }
    }
    return false;
}
int32_t main()
{
    fast();
    int test;   cin >> test;
    while (test--)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < 26; i++)
            cin >> v[i];
        int cost;   cin >> cost;
        string res;
        solve(v, cost, res);
    }
    return 0;
}