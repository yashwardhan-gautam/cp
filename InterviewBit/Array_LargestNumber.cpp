// Given a list of non negative integers, arrange them such that they form the largest number.
bool compare(string x, string y)
{
	string xy = x + y;
	string yx = y + x;
	return xy > yx;
}
string Solution::largestNumber(const vector<int> &A) {
	vector<string> v;
	for (int i = 0; i < A.size(); i++)
		v.push_back(to_string(A[i]));
	sort(v.begin(), v.end(), compare);
	string ans;
	for (int i = 0; i < v.size(); i++)
		ans += v[i];
	if (ans[0] == '0' and ans[ans.size() - 1] == '0')
		return "0";
	return ans;
}