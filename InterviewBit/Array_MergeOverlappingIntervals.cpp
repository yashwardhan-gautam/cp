// Given a collection of intervals, merge all overlapping intervals.
bool compare(Interval a, Interval b)
{
	return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
	sort(A.begin(), A.end(), compare);
	vector<Interval> res;
	res.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		if (res[res.size() - 1].end >= A[i].start)
			res[res.size() - 1].end = max(res[res.size() - 1].end, A[i].end);
		else
			res.push_back(A[i]);
	}
	return res;
}