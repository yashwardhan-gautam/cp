//You are given a read only array of n integers from 1 to n.
//Each integer appears exactly once except A which appears twice and B which is missing.
//Return A and B.
#define ll long long int
vector<int> Solution::repeatedNumber(const vector<int> &A)
{
	int n = A.size();
	ll sum = 0, sumsq = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += (ll)A[i];
		sumsq += (ll)(A[i] * A[i]);
	}
	ll diff = (n * (n + 1)) / 2 - sum;
	ll diff2 = (n * (n + 1) * (2 * n + 1)) / 6 - sumsq;
	ll sumi = diff2 / diff;
	int repeated = (int)(sumi - diff) / 2;
	int missing = (int)(diff + sumi) / 2;
	vector<int> ans;
	ans.push_back(repeated);
	ans.push_back(missing);
	return ans;
}
