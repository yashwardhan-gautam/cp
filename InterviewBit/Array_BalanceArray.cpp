//Given an integer array A of size N. You need to count the number of special elements in the given array.
//A element is special if removal of that element make the array balanced.
//Array will be balanced if sum of even index element equal to sum of odd index element.
int Solution::solve(vector<int> &A)
{
	int n = A.size();
	vector<int> left_odd(n), left_even(n), right_odd(n), right_even(n);
	int even_sum = 0, odd_sum = 0;
	for (int i = 0; i < n; i++)
	{
		left_odd[i] = odd_sum;
		left_even[i] = even_sum;
		if (i & 1) odd_sum += A[i];
		else    even_sum += A[i];
	}
	even_sum = 0, odd_sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		right_odd[i] = odd_sum;
		right_even[i] = even_sum;
		if (i & 1) odd_sum += A[i];
		else    even_sum += A[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (left_odd[i] + right_even[i] == left_even[i] + right_odd[i])
			ans++;
	}
	return ans;
}
