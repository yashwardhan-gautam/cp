//Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.
int Solution::solve(vector<int> &A) {
	int mi = A[0];
	int ma = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		mi = min(mi, A[i]);
		ma = max(ma, A[i]);
	}
	return ma + mi;
}
