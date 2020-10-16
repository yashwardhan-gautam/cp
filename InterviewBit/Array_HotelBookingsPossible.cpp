// A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
	vector<pair<int, int> > v;
	for (int i = 0; i < arrive.size(); i++)
		v.push_back({arrive[i], 1});
	for (int i = 0; i < depart.size(); i++)
		v.push_back({depart[i], -1});
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		count += v[i].second;
		if (count > K)
			return false;
	}
	return true;
}
