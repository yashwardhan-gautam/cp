#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	vector<int> v(26,0);
	for(int i=0;i<s.size();i++)	v[s[i]-'a']++;
	int dis_count=0;
	for(int i=0;i<26;i++)	
	{
		if(v[i]!=0) dis_count++;
	}
	//cout<<dis_count<<"\n";
	if(dis_count&1)		cout<<"IGNORE HIM!\n";
	else 				cout<<"CHAT WITH HER!\n";
	
	return 0;
}
