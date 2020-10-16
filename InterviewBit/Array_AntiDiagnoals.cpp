// Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > res(2 * n - 1);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int row = 0, col = i;
		while (row<n and col >= 0)
		{
			res[c].push_back(A[row][col]);
			row++;
			col--;
		}
		c++;
	}
	for (int i = 1; i < n; i++)
	{
		int row = i, col = n - 1;
		while (row<n and col >= 0)
		{
			res[c].push_back(A[row][col]);
			row++;
			col--;
		}
		c++;
	}
	return res;
}