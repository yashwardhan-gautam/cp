// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
void Solution::setZeroes(vector<vector<int> > &A) {
	int r1 = 0, c1 = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i][0] == 0)
		{
			r1 = 1;
			break;
		}
	}
	for (int i = 0; i < A[0].size(); i++)
	{
		if (A[0][i] == 0)
		{
			c1 = 1;
			break;
		}
	}
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			if (A[i][j] == 0)
				A[i][0] = 0, A[0][j] = 0;
		}
	}
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 1; j < A[0].size(); j++)
		{
			if (A[i][0] == 0 or A[0][j] == 0)
				A[i][j] = 0;
		}
	}
	if (r1)
	{
		for (int i = 0; i < A.size(); i++)
			A[i][0] = 0;
	}
	if (c1)
	{
		for (int i = 0; i < A[0].size(); i++)
			A[0][i] = 0;
	}
}
