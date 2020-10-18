/*Amazon would like to know how much inventory exists in their closed inventory compartments. Given a string s
consisting of items as "*" and closed compartments as an open and close "|", an array of starting indices
startIndices, and an array of ending indices endIndices, determine the number of items in closed compartments
within the substring between the two indices, inclusive.
An item is represented as an asterisk ('*' = ascii decimal 42)
A compartment is represented as a pair of pipes that may or may not have items between them ('|' = ascii decimal 124).

Example
s = '|**|*|*'

startIndices = [1, 1]
endIndices = [5, 6]

The string has a total of 2 closed compartments, one with 2 items and one with 1 item. For the first pair of
indices, (1, 5), the substring is '|**|*'. There are 2 items in a compartment.
For the second pair of indices, (1, 6), the substring is '|**|*|' and there are 2 + 1 = 3 items in compartments.
Both of the answers are returned in an array, [2, 3].*/

#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl		 	      "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector<int> solve(string s, vector<int> start_index, vector<int> end_index)
{
	int n = s.size();
	vector<int> left(n), right(n), stars(n);
	int pre_left = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '|')
			pre_left = i;
		left[i] = pre_left;
	}
	int pre_right = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '|')
			pre_right = i;
		right[i] = pre_right;
	}
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')	c++;
		stars[i] = c;
	}
	vector<int> res;
	for (int i = 0; i < start_index.size(); i++)
	{
		int a = right[start_index[i] - 1];
		int b = left[end_index[i] - 1];
		if (a >= b)	res.push_back(0);
		else 			res.push_back(stars[b] - stars[a]);
	}
	return res;
}
int32_t main()
{
	fast();
	string s;	cin >> s;
	int n;	cin >> n;
	vector<int> start_index(n), end_index(n);
	for (int i = 0; i < n; i++)	cin >> start_index[i];
	for (int i = 0; i < n; i++)	cin >> end_index[i];
	vector<int> v = solve(s, start_index, end_index);
	for (auto it : v)
		cout << it << "\n";
	return 0;
}

TC:
/*

|**|***|*|****|
2
9 5
15 14

*/