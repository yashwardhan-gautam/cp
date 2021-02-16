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
int solve1(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 4 * 4 - 1; i++)
	{
		for (int j = i + 1; j < 4 * 4; j++)
		{
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	}
	return inv_count;
}
int findXPosition(int puzzle[4][4])
{
	for (int i = 4 - 1; i >= 0; i--)
		for (int j = 4 - 1; j >= 0; j--)
			if (puzzle[i][j] == 0)
				return 4 - i;
	return 0;
}
bool solve(int mat[4][4])
{
	int invcount = solve1((int*)mat);
	int pos = findXPosition(mat);
	if (pos & 1)
		return !(invcount & 1);
	else
		return invcount & 1;
}
int32_t main()
{
	fast();
	int mat[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> mat[i][j];
	cout << solve(mat);
	return 0;
}