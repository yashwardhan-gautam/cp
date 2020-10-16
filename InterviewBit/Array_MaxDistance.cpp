//Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
int Solution::maximumGap(const vector<int> &A) {
	int n = A.size();
	vector<pair<int, int > > v(n); //data,index pair
	for (int i = 0; i < n; i++)
	{
		v[i].first = A[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int min_till_now = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (v[i].second < min_till_now)
			min_till_now = v[i].second;
		ans = max(ans, v[i].second - min_till_now);
	}
	return ans;
}
