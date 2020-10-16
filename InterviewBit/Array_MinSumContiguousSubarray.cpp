// Find the contiguous subarray within an array, A of length N which has the largest sum.
int Solution::maxSubArray(const vector<int> &A) {
	vector<int> v(A);
	int ans = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		if (v[i - 1] > 0)
			v[i] += v[i - 1];
		ans = max(ans, v[i]);
	}
	return ans;
}
