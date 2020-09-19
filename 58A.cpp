#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	string s1="hello";
	int index=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s1[index])
			index++;
	}
	if(index==s1.size())	cout<<"YES\n";
	else 					cout<<"NO\n";
	return 0;
}
