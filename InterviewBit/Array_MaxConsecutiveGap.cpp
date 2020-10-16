//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
int Solution::maximumGap(const vector<int> &A) {
	vector<int> B(A);
	sort(B.begin(), B.end());
	int ans = 0;
	for (int i = 0; i < B.size() - 1; i++)
		ans = max(ans, B[i + 1] - B[i]);
	return ans;
}

