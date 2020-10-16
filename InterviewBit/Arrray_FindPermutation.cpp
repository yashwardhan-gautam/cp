// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
//D means the next number is smaller, while I means the next number is greater.
vector<int> Solution::findPerm(const string A, int B) {
	vector<int> v;
	int s = 1, e = B;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == 'I')
			v.push_back(s++);
		else
			v.push_back(e--);
	}
	v.push_back(s);
	return v;
}