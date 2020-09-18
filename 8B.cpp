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

int32_t main()
{
	fast();
	string s; cin >> s;
	int pos[400][400] = {0};
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			pos[i][j] = 1e5;
	bool flag = false;
	int x = 150, y = 150;
	int dis = 1;
	pos[x][y] = dis++;
	for (int i = 0; i < s.size(); i++)
	{
		//cout << x << " " << y << endl;
		if (s[i] == 'L')
			x--;
		if (s[i] == 'R')
			x++;
		if (s[i] == 'U')
			y++;
		if (s[i] == 'D')
			y--;
		if (pos[x][y] != 1e5 or (min(min(pos[x - 1][y], pos[x + 1][y]), min(pos[x][y + 1], pos[x][y - 1]))) + 1 < dis)
		{
			flag = true;
			break;
		}
		pos[x][y] = dis++;
	}
	if (flag)
		cout << "BUG\n";
	else
		cout << "OK\n";
	return 0;
}