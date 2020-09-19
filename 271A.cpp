#include<bits/stdc++.h>
using namespace std;
bool all_distinct(int n)
{
	unordered_set<int> s;
	while(n)
	{
		if(s.find(n%10)!=s.end())	return false;
		s.insert(n%10);
		n=n/10;
	}
	return true;
}
int main()
{
	int n;	cin>>n;
	for(int i=n+1;i<INT_MAX;i++)
	{
		if(all_distinct(i))
		{
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
