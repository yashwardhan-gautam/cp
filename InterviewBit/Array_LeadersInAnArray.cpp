//Given an integer array A containing N distinct integers, you have to find all the leaders in the array A.
//An element is leader if it is strictly greater than all the elements to its right side.
vector<int> Solution::solve(vector<int> &A) {
	int n = A.size();
	vector<int> ans;
	int high = A[A.size() - 1];
	ans.push_back(high);
	for (int i = n - 2; i >= 0; i--)
	{
		if (A[i] > high)
		{
			high = A[i];
			ans.push_back(high);
		}
	}
	return ans;
}