/*
A new Amazon developed scaling computing system checks the average utilization of the computing system  every second while it monitors. It implements an autoscale policy to add or reduce instances depending on the current load as described below.
Once an action of adding or reducing the number of instances is performed, the system will stop monitoring for 10 seconds. During that time the number of instances does not change.

1. Average utilization<25%, an action is instantiated to reduce the number of instaces by half if the number of instances by half if the number of instances is greater than 1(take the cieling if the number is not an integer). If the number of instances 1,take no action.
2. 25% <= Average utilization<= 60%.  Take no action.
3. Average utilization>60%. An actinon is instantiated to double the number of instances if the doubled value does not exceed 2*10^8. If the number of instances exceeds this limit upon doubling, perform no action.

Given an array of integer that represent the average utilization at each second, determine the number of instances at the end of the time frame.

Example-
instances- 2
averageUtil = [25,23,1,2,3,4,5,7,8,9,10,76,80]

1. At second 1, the average utilization = 25<=25. Take no action.
2. At second 2, the average utilization = 23<25, reduce the number of instaces by half, 2/2=1
3. Since the action was taken, the system will stop checking for 10 seconds, from averageUtil[2] to averageUtil[11].
4. At average utilization[12]=76.76>60, so reduce the number of instances is doubled from 1 to 2.
5. Tehre are no more readins to  consider and 2 is the final answer.
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
int finalInstance(int instaces, vector<int> averageUtil)
{
	int index = 0;
	while (index < averageUtil.size())
	{
		if (averageUtil[index] >= 25 and averageUtil[index] <= 60)
			index++;
		else if (averageUtil[index] < 25)
		{
			if (instaces != 1)
				instaces = ceil(instaces / 2);
			index += 11;
		}
		else if (averageUtil[index] > 25)
		{
			if (2 * instaces <= 200000000)
				instaces *= 2;
			index += 11;
		}
	}
	return instaces;
}
int32_t main()
{
	fast();
	int instaces;	cin >> instaces;
	int n;	cin >> n;
	vector<int> averageUtil(n);
	for (int i = 0; i < n; i++)	cin >> averageUtil[i];
	cout << finalInstance(instaces, averageUtil) << endl;
	return 0;
}