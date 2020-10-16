// You are given a 1D integer array B containing A integers.
// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.
// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])
int Solution::solve(int A, vector<int> &B) {
	int sum = 0;
	for (int i = 0; i < A.size(); i++) sum += A[i];
	if (sum % 3 != 0) return 0;
	int by3 = 0;
	int s = 0;
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		s += A[i];
		if (s == 2 * sum / 3 and by3)
			ans += by3;
		if (s == sum / 3)
			by3++;
	}
	return ans;
}
