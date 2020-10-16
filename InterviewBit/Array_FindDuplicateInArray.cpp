//Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
int Solution::repeatedNumber(const vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
	{
		if (A[abs(A[i]) - 1] < 0)
			return A[i];
		else
			A[abs(A[i]) - 1] *= -1;
	}
	return -1;
}
