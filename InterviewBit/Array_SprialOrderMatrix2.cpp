//Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
vector<vector<int> > Solution::generateMatrix(int A) {
	int count = 1;
	vector<vector<int> > v(A, vector<int> (A));
	int c = 0;
	int l = 0, r = A - 1, t = 0, b = A - 1;
	while (l <= r and t <= b)
	{
		if (c == 0)
		{
			for (int k = l; k <= r; k++)   v[t][k] = count, count++;
			t++;
		}
		else if (c == 1)
		{
			for (int k = t; k <= b; k++)   v[k][r] = count, count++;
			r--;
		}
		else if (c == 2)
		{
			for (int k = r; k >= l; k--)    v[b][k] = count, count++;
			b--;
		}
		else if (c == 3)
		{
			for (int k = b; k >= t; k--)   v[k][l] = count, count++;
			l++;
		}
		c = (c + 1) % 4;
	}
	return v;
}
