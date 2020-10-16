// Given a sorted array A containing N integers both positive and negative.
//You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.
//Try to this in O(N) time.
vector<int> Solution::solve(vector<int> &A)
{
	int n = A.size();
	int l = 0;
	int r = n - 1;
	vector<int> res(n);
	int index = n - 1;
	while (l <= r)
	{
		int sql = A[l] * A[l];
		int sqr = A[r] * A[r];
		if (sql > sqr)
		{
			res[index--] = sql;
			l++;
		}
		else
		{
			res[index--] = sqr;
			r--;
		}
	}
	return res;
}
