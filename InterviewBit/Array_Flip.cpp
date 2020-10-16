//You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
//Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
vector<int> Solution::flip(string A) {
	int n = A.size();
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		if (A[i] == '0') v[i] = 1;
		else         		 v[i] = -1;
	}
	int max_sum = INT_MIN;
	int l = 0, l_ans = 0, r_ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum < 0)
		{
			l = i + 1;
			sum = 0;
		}
		else if (sum > max_sum)
		{
			l_ans = l;
			r_ans = i;
			max_sum = sum;
		}
	}
	if (max_sum < 0) return {};
	return {l_ans + 1, r_ans + 1};
}