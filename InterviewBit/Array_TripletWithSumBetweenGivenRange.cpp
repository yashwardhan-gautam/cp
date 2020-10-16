//Given an array of real numbers greater than zero in form of strings.
//Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
//Return 1 for true or 0 for false.
int Solution::solve(vector<string> &A) {
	if (A.size() < 3)
		return 0;
	vector<double> v;
	for (int i = 0; i < A.size(); i++)
		v.push_back(stof(A[i]));
	float a = v[0], b = v[1], c = v[2];
	for (int i = 3; i < A.size(); i++)
	{
		if (a + b + c > 1.0 and a + b + c < 2.0) return 1;
		else if (a + b + c >= 2.0)
		{
			if (a > b and a > c)         a = v[i];
			else if (b > a and b > c)    b = v[i];
			else                    c = v[i];
		}
		else if (a + b + c <= 1)
		{
			if (a < b and a < c)         a = v[i];
			else if (b < a and b < c)    b = v[i];
			else if (c < a and c < b)    c = v[i];
		}
	}
	return (a + b + c > 1.0 and a + b + c < 2.0);
}