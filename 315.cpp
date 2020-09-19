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
void print_temp(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
vector<int> countSmaller(vector<int>& nums) {
	vector <int> ans;
	vector <int> temp;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
		temp.insert(temp.begin() + ind, nums[i]);
		print_temp(temp);
		ans.insert(ans.begin(), ind);
	}
	//reverse(ans.begin(), ans.end());
	return ans;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); i++)
		cin >> nums[i];
	vector<int> ans = countSmaller(nums);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}