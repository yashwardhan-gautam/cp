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
}
bool can_place(int mat[][9], int i, int j, int n, int number)
{
	for (int k = 0; k < n; k++)
	{
		if (mat[i][k] == number or mat[k][i] == number)
			return false;
	}
	n = sqrt(n);
	int starti = (i / n) * n;
	int startj = (j / n) * n;
	for (int k = starti; k < starti + n; k++)
	{
		for (int l = startj; l < startj + n; l++)
		{
			if (mat[k][l] == number)
				return false;
		}
	}
	return true;
}
bool solve(int mat[][9], int i, int j, int n)
{
	//cout << i << " " << j << endl;
	if (j == n)
	{
		i++;
		j = 0;
	}
	if (i == n)
	{
		cout << "sudoku solved\n";
		return true;
	}

	if (mat[i][j] != 0)
		return solve(mat, i, j + 1, n);
	for (int number = 1; number <= 9; number++)
	{
		if (can_place(mat, i, j, n, number))
		{
			mat[i][j] = number;
			if (solve(mat, i, j + 1, n))
				return true;
			mat[i][j] = 0;
		}
	}
	return false;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	int mat[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> mat[i][j];
	solve(mat, 0, 0, n);
	return 0;
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/