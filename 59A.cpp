#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("ouput.txt","w",stdout);
    #endif
	string s;	cin>>s;
	int l=0;
	int u=0;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='a' and s[i]<='z') l++;
		else u++;
	}
	//cout<<l<<" "<<u<<"\n";
	if(l>=u)
	{
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]>='a' and s[i]<='z') cout<<s[i];
			else cout<<char(s[i]+'a'-'A');
		}
	}
	else if(l<u)
	{
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]>='a' and s[i]<='z') cout<<char(s[i]+'A'-'a');
			else cout<<(char)(s[i]);
		}
	}
	cout<<"\n";
	return 0;
}
