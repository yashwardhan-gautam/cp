// You are in an infinite 2D grid where you can move in any of the 8 directions
//You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
	int ans = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		int dx = abs(A[i] - A[i + 1]);
		int dy = abs(B[i] - B[i + 1]);
		ans += max(dx, dy);
	}
	return ans;
}