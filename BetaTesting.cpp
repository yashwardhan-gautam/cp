/*A new team at Amazon is doing an internal beta test before their first release. The testing consists of executing tasks in a particular order, with each task having an assigned complexity. The team has already planned the order in which the tasks have to be executed, but these now need to be scheduled across several days. The goal is to have at least one task sent to the beta testers every day and to plan the tasks in a way that minimizes the overall complexity of the test. The test is considered complete once all the tasks have been executed. Given the complexity of the tasks, as well as how many days the test is running, what is the overall minimum complexity that can be achieved with optimal planning?

For example, let's say there are n = 5 tasks, where complexity = [1,5, 3, 2, 4), and the length of the test is days = 2. (Note that complexity denotes both the assigned complexity of each task as well as the order in which they need to be executed.) The best option is to execute the first task on the first day and the rest on the second day. The complexity of the first day would be 1, since that's the only task, and the complexity of the second day would be 5, because that's the complexity level of the most complex task that day. Therefore, the answer is 1 + 5 = 6.

Example 1:
5 -> complexity[] size n = 5
30
10
40
20
50
2 -> Days =2

Output: 80

Example 2:
6 -> complexity[] size n = 6
74303
20452
66120
44483
5370
68585
5 -> Days =5

Output: 234830
Explanation: task 3 and 4 on same day*/
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
int solve(vector<int> &job, int index, int d, vector<vector<int> > &dp)
{
	if (d == 0)
	{
		if (index == job.size())
			return 0;
		else
			return INT_MAX;
	}
	if (index == job.size())
		return INT_MAX;
	if (dp[index][d] != -1)
		return dp[index][d];
	int ma = 0;
	int res = INT_MAX;
	for (int i = index; i <= job.size() - d; i++)
	{
		ma = max(ma, job[i]);
		res = min(res, ma + solve(job, i + 1, d - 1, dp));
	}
	return dp[index][d] = res;
}
int findMinComplexity(vector<int> &job, int days) {
	if (days > job.size())
		return -1;
	vector<vector<int> > dp(job.size(), vector<int> (days + 1, -1));
	return solve(job, 0, days, dp);
}

int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> job(n);
	for (int i = 0; i < n; i++)	cin >> job[i];
	int day;
	cin >> day;
	cout << findMinComplexity(job, day) << endl;
	return 0;
}