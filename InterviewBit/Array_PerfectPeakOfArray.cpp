// Given an integer array A of size N.
// You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
// If it exists return 1 else return 0.
int Solution::perfectPeak(vector<int> &A) {
	int n = A.size();
	int l[n], r[n];
	l[0] = A[0];
	for (int i = 1; i < n; i++)    l[i] = max(A[i], l[i - 1]);
	r[n - 1] = A[n - 1];
	for (int i = n - 2; i >= 0; i--) r[i] = min(A[i], r[i + 1]);
	for (int i = 1; i < A.size() - 1; i++)
		if (A[i] > l[i - 1] and A[i] < r[i + 1])
			return 1;
	return 0;
}
