// the string can never have three or more consecutive 4s and the string can never start with 4
// provided the string doesn't contain any other number than 1 and 4
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1' and s[i]!='4')
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		if(s.find("444")==string::npos and s[0]!='4')	cout<<"YES\n";
		else cout<<"NO\n";
	}
	else cout<<"NO\n";
	return 0;
}
