// Given an index k, return the kth row of the Pascal’s triangle.
//Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
vector<int> Solution::getRow(int k) {
	vector<int> v(k + 1);
	v[0] = 1;
	if (k == 0)    return v;
	int c = 1;
	for (int i = 1; i <= k; i++)
	{
		v[i] = (c * (k - i + 1)) / i;
		c = v[i];
	}
	return v;
}