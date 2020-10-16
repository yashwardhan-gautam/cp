// Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.
int Solution::solve(vector<vector<int> > &A, int B) {
	int n = A.size();
	int ans = INT_MIN;
	vector<vector<int> > rc(n, vector<int> (n, 0));
	vector<vector<int> > c(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				rc[i][j] = A[i][j];
			else
			{
				rc[i][j] = A[i][j] + rc[i][j - 1];
				if (j - B >= 0)
					rc[i][j] -= A[i][j - B];
			}
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				c[i][j] = rc[i][j];
			else
			{
				c[i][j] = rc[i][j] + c[i - 1][j];
				if (i - B >= 0)
					c[i][j] -= rc[i - B][j];
			}
			if (i >= B - 1 and j >= B - 1)
				ans = max(ans, c[i][j]);
		}
	}
	return ans;
}
