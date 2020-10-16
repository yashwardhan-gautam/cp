//Given numRows, generate the first numRows of Pascal’s triangle.
//Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
vector<vector<int> > Solution::solve(int n)
{
	if (!n)
		return {};
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++)    v[i].resize(i + 1);
	v[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				v[i][j] = v[i - 1][j];
			else if (i == j)
				v[i][j] = v[i - 1][j - 1];
			else
				v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
		}
	}
	return v;
}
