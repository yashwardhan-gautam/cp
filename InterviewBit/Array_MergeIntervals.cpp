//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//You may assume that the intervals were initially sorted according to their start times.
bool compare(Interval a, Interval b)
{
	return a.start < b.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
	for (int i = 0; i < intervals.size(); i++)
		if (intervals[i].start > intervals[i].end)
			swap(intervals[i].start, intervals[i].end);
	if (newInterval.start > newInterval.end)
		swap(newInterval.start, newInterval.end);
	intervals.push_back(newInterval);
	sort(intervals.begin(), intervals.end(), compare);

}
