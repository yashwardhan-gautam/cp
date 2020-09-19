#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2,s3;	cin>>s1>>s2>>s3;
	vector<int> v1(26,0);
	vector<int> v2(26,0);
	vector<int> v3(26,0);
	for(int i=0;i<s1.size();i++)	v1[s1[i]-'A']++;
	for(int i=0;i<s2.size();i++)	v2[s2[i]-'A']++;
	for(int i=0;i<s3.size();i++)	v3[s3[i]-'A']++;
	if(s3.size()==s1.size()+s2.size())
	{
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if(v3[i]!=v1[i]+v2[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1) cout<<"NO\n";
		else   		cout<<"YES\n";	
	}
	else 
		cout<<"NO\n";
	return 0;
}
