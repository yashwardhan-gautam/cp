/*
Imagine a small Amazon Go store that has exactly one turnstile. It can be used by customers either as an entrance or an exit. Sometimes multiple customers want to pass through the turnstile and their directions can be different. The ith customer comes to the turnstile at time[i] and wants to either exit the store if direction [i] = 1 or enter the store if direction[i] = 0. Customers form 2 queues, one to exit and one to enter. They are ordered by the time when they came to the turnstile and, if the times are equal, by their indices.
If one customer wants to enter the store and another customer wants to exit at the same moment, there are three cases:
If in the previous second the turnstile was not used (maybe it was used before, but not at the previous second), then the customer who wants to exit goes first.
If in the previous second the turnstile was used as an exit, then the customer who wants to leave goes first.
If in the previous second the turnstile was used as an entrance, then the customer who wants to enter goes first.
Passing through the turnstile takes 1 second.
Write an algorithm to find the time for each customer when they will pass through the turnstile.
Input

The function/method consists of three arguments:

numcustomers, an integer representing the number of customers (n);
arrTime, a list of integers where the value at indexi is the time in seconds when the ith customer will come to the turnstile;
direction, a list of integers where the value at indexi is the direction of the ith customer.

Output

Return a list of integers where the value at index i is the time when the ith customer will pass the turnstile.

Constraints

1 <= numCustomers <= 10^5
0 <= arrTime[i] <= arrTime[i + 1] <= 10^9
0 <= i <= numCustomers - 2
0 <= direction[i] <= 1
0 <= j <= numCustomers - 1

Examples

Example 1:
Input:
numCustomers = 4
arrTime = [0, 0, 1,5]
direction = [0, 1, 1, 0]
Output:
[2,0,1,5]
Explanation:
At time 0, customer 0 and 1 want to pass through the turnstile. Customer 0 wants to enter the store and customer 1 wants to leave the store. The turnstile was not used in the previous second, so the priority is on the side of the customer 1
At time 1, customers 0 and 2 want to pass through the turnstile. Customer 2 wants to leave the store and at the previous second the turnstile was used as an exit, so the customer 2 passes through the turnstile.
At time 2, customer 0 passes through the turnstile.
At time 5, customer 3 passes through the turnstile.

Example 2
Input:
numCustomers = 5
arrTime = [0,1,1,3,3]
direction = [0, 1, 0, 0, 1]
Output: [0, 2, 1, 4, 3]
Explanation:
At time 0, customer 0 passes through the turnstile (enters).
At time 1, customers 1 (exit) and 2 (enter) want to pass through the turnstile, and customer 2 passes through the turnstile because their direction is equal to the direction at the previous second.
At time 2. customer 1 passes through the turnstile (exit).
At time 3, customers 3 (enter) and 4 (exit) want to pass through the turnstile. Customer 4 passes through the turnstile because at the previous second the turnstile was used to exit.
At time 4, customer 3 passes through the turnstile
*/


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
struct person {
	int index, start_time, dir;
};
// sort her as per the start time
// if the start time is same, the one going out (dir==1), should be put first
// if the satrt time and direction both are same, then the lower index comes first
// since, the priority queue, is max heap, we compare in opposite sense
struct compare {
	bool operator()(const person &a, const person &b)
	{
		if (a.start_time == b.start_time)
		{
			if (a.dir == b.dir)
				return a.index > b.index;
			return a.dir < b.dir;
		}
		return a.start_time > b.start_time;
	}
};

vector<int> pass_through_turnstile(int n, vector<int> &start, vector<int> &dir)
{
	priority_queue<person, vector<person>, compare>	pq;
	for (int i = 0; i < start.size(); i++)
		pq.push({i, start[i], dir[i]});

	vector<int> res(n, 0);
	int prev_dir = -1;
	int time = 0;
	while (!pq.empty())
	{
		int idx = pq.top().index, second = pq.top().start_time, direction = pq.top().dir;
		pq.pop();
		if (second != time)
			prev_dir = -1;
		if (!pq.empty() and pq.top().start_time == second)
		{
			// if in the previous second the turnstile was used as entrance
			// then the customer who wants to enter goes first
			if (prev_dir == 0 and pq.top().dir == 0)
			{
				int a0 = pq.top().index, b0 = pq.top().start_time, c0 = pq.top().dir;
				pq.pop();
				pq.push({idx, second, direction});
				idx = a0, second = b0, direction = c0;
			}
		}
		res[idx] = second;
		prev_dir = direction;
		time = second;
		while (!pq.empty() and pq.top().start_time == second)
		{
			idx = pq.top().index;
			second = pq.top().start_time;
			direction = pq.top().dir;
			pq.pop();
			pq.push({idx, second + 1, direction});
		}
		time++;
	}
	return res;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> start(n);
	vector<int> dir(n);
	for (int i = 0; i < n; i++)	cin >> start[i];
	for (int i = 0; i < n; i++)	cin >> dir[i];
	vector<int> ans = pass_through_turnstile(n, start, dir);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}