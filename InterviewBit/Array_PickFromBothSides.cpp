//Given an integer array A of size N.
//You can pick B elements from either left or right end of the array A to get maximum sum.
//Find and return this maximum possible sum.
int Solution::solve(vector<int> &A, int B) {
	int sum = 0, n = A.size();
	for (int i = n - 1; i >= n - B; i--)   sum += A[i];
	int ans = sum;
	for (int i = 0; i < B; i++)
	{
		sum += A[i] - A[n - B + i];
		ans = max(ans, sum);
	}
	return ans;
}
