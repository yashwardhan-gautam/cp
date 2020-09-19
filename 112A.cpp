#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='A' and s1[i]<='Z')
			s1[i]=s1[i]+'a'-'A';
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='A' and s2[i]<='Z')
			s2[i]=s2[i]+'a'-'A';
	}
	if(s1<s2)	cout<<"-1\n";
	else if(s1==s2)	cout<<"0\n";
	else 			cout<<"1\n";
	return 0;
}
