/*
Amazon Fresh is running a promotion in which customers receive prizes for purchasing a secret combination of fruits. The combination will change each day, and the team running the promotion wants to use a code list to make it easy to change the combination. The code list contains groups of fruits. Both the order of the groups within the code list and the order of the fruits within the groups matter. However, between the groups of fruits, any number, and type of fruit is allowable. The term "anything" is used to allow for any type of fruit to appear in that location within the group.
Consider the following secret code list: [[apple, apple], [banana, anything, banana]]
Based on the above secret code list, a customer who made either of the following purchases would win the prize:
orange, apple, apple, banana, orange, banana
apple, apple, orange, orange, banana, apple, banana, banana
Write an algorithm to output 1 if the customer is a winner else output 0.
*/

/*
Input
The input to the function/method consists of two arguments:
codeList, a list of lists of strings representing the order and grouping of specific fruits that must be purchased in order to win the prize for the day.
shoppingCart, a list of strings representing the order in which a customer purchases fruit.
Output
Return an integer 1 if the customer is a winner else return 0.
Note
'anything' in the codeList represents that any fruit can be ordered in place of 'anything' in the group. 'anything' has to be something, it cannot be "nothing."
'anything' must represent one and only one fruit.
If secret code list is empty then it is assumed that the customer is a winner.
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
bool find(vector<vector<string> > cl, vector<string> shop)
{
	if (cl.size() == 0)
		return 1;
	if (shop.size() == 0)
		return 0;
	int i = 0, j = 0;
	for (int k = 0; k < shop.size(); k++)
	{
		if (cl[i][j] == shop[k] or cl[i][j] == "anything")
		{
			j++;
			if (j == cl[i].size())
				i++, j = 0;
			if (i == cl.size())
				return 1;
		}
		else
		{
			k -= j;
			j = 0;
		}
	}
	return 0;
}
int32_t main()
{
	fast();
	vector<vector<string>> codeList1 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
	vector<string> shoppingCart1 = {"orange", "apple", "apple", "banana", "orange", "banana"};
	vector<vector<string>> codeList2 =  { { "apple", "apple" }, { "banana", "anything", "banana" } };
	vector<string> shoppingCart2 = {"banana", "orange", "banana", "apple", "apple"};
	cout << find(codeList1, shoppingCart1) << endl;
	cout << find(codeList2, shoppingCart2) << endl;
	return 0;
}