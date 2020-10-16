//You are given an n x n 2D matrix representing an image.
//Rotate the image by 90 degrees (clockwise).
//You need to do this in place.
void Solution::rotate(vector<vector<int> > &A)
{
	int n = A.size();
	// take transpose first
	for (int i = 0; i < A.size(); i++)
		for (int j = i + 1; j < A.size(); j++)
			swap(A[i][j], A[j][i]);

	// exchange the elements in first and second half
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n / 2; j++)
			swap(A[i][j], A[i][n - 1 - j]);

}
