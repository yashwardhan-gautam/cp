//You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
//Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
//If A is already sorted, output -1.
vector<int> Solution::subUnsort(vector<int> &A)
{
	int s = -1, e = -1;
	int n = A.size();
	vector<int> res;
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			s = i;
			break;
		}
	}
	if (s == -1)
		res.push_back(-1);
	return res;
	for (int i = n - 1; i > 0; i--)
	{
		if (A[i - 1] > A[i])
		{
			e = i;
			break;
		}
	}
	int mi = A[s], ma = A[s];
	for (int i = s + 1; i <= e; i++)
	{
		mi = min(A[i], mi);
		ma = max(A[i], ma);
	}
	for (int i = 0; i < s; i++)
	{
		if (A[i] > mi)
		{
			s = i;
			break;
		}
	}
	for (int i = n - 1; i > e; i--)
	{
		if (A[i] < ma)
		{
			e = i;
			break;
		}
	}
	res.push_back(s);
	res.push_back(e);
	return res;
}
