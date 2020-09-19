#include<bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
	if(c=='a' or c=='e' or c=='i' or c=='o' or  c=='u' or c=='y')	return true;
	if(c=='A' or c=='E' or c=='I' or c=='O' or  c=='U' or c=='Y')	return true;
	return false;
}
int main()
{
	string s;	cin>>s;
	string ans;
	for(int i=0;i<s.size();i++)
		if(!isvowel(s[i]))	ans+=s[i];
	string ans1,ans2;
	for(int i=0;i<ans.size();i++)
		ans1=ans1+"."+char(ans[i]);
	for(int i=0;i<ans1.size();i++)
	{
		if(isupper(ans1[i]))	ans2=ans2+char(ans1[i]-'A'+'a');
		else 					ans2+=ans1[i];
	}
	//cout<<ans<<" "<<ans1<<"\n";
	cout<<ans2<<"\n";
	return 0;
}

//this also works
/*
#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool isvowel(char c)
{
	if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='y')	return true;
	else if(c=='A' or c=='E' or c=='I' or c=='O' or  c=='U' or c=='Y') return true;
	return false; 
}
int32_t main()
{
	string s;	cin>>s;
	string ans;
	for(int i=0;i<s.size();i++)
	{
		if(!isvowel(s[i]))
		{
			char c=s[i];
			if(isupper(c))	ans=ans+"."+char(c-'A'+'a');
			else 			ans=ans+"."+char(c);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
 */ 
