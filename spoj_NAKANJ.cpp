// https://www.spoj.com/problems/NAKANJ/
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
	string s, d;
	cin >> s >> d;
	pair<int, int> src = {s[0] - 'a', s[1] - '0' - 1};
	pair<int, int> dest = {d[0] - 'a', d[1] - '0' - 1};
	vector<vector<bool> > vis(8, vector<bool> (8, 0));
	vector<vector<int> > dis(8, vector<int> (8, -1));
	vis[s[0] - 'a'][s[1] - '0' - 1] = true;
	dis[s[0] - 'a'][s[1] - '0' - 1] = 0;
	queue<pair<int, int> > q;
	q.push(src);
	int x[] = {1, 2, 1, 2, -1, -2, -1, -2};
	int y[] = {2, 1, -2, -1, 2, 1, -2, -1};
	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		if (dis[dest.fi][dest.se] != -1)
			return dis[dest.fi][dest.se];
		for (int i = 0; i < 8; i++)
		{
			int x1 = curr.fi + x[i];
			int y1 = curr.se + y[i];
			if (x1 >= 0 and x1<8 and y1 >= 0 and y1 < 8 and !vis[x1][y1])
			{
				vis[x1][y1] = true;
				dis[x1][y1] = dis[curr.fi][curr.se] + 1;
				q.push({x1, y1});
			}
		}
	}
	return dis[dest.fi][dest.se];
}
int32_t main()
{
	fast();
	int t;	cin >> t;
	while (t--)
		cout << solve() << endl;
	return 0;
}