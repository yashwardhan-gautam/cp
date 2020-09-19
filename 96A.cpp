#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	if(s.find("1111111")!=string::npos or s.find("0000000")!=string::npos)
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
