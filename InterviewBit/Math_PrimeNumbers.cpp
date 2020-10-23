vector<int> Solution::sieve(int n) {
	vector<int> ans;
	if (n < 2) {
		return ans;
	}

	int arr[n + 1];
	memset(arr, 0, sizeof(arr));
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			ans.push_back(i);
			for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
		}
	}
	return ans;
}
