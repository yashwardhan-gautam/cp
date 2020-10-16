//Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
//If such arrangement is not possible, it must be rearranged as the lowest possible order.
vector<int> Solution::nextPermutation(vector<int> &A) {
	int n = A.size();
	int i, j;
	for (i = n - 2; i >= 0; i--)
		if (A[i] < A[i + 1])
			break;
	if (i == -1)
	{
		reverse(A.begin(), A.end());
		return A;
	}
	for (j = n - 1; j > i; j--)
		if (A[j] > A[i])
			break;
	swap(A[i], A[j]);
	reverse(A.begin() + i + 1, A.end());
	return A;
}
