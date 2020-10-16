// Given a non-negative number represented as an array of digits,
//add 1 to the number ( increment the number represented by the digits ).
//The digits are stored such that the most significant digit is at the head of the list.
vector<int> Solution::plusOne(vector<int> &A) {
	int carry = 1;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		int sum = A[i] + carry;
		A[i] = sum % 10;
		carry = sum / 10;
	}
	while (carry != 0)
	{
		A.insert(A.begin(), carry % 10);
		carry /= 10;
	}
	while (A[0] == 0)
		A.erase(A.begin());
	return A;
}