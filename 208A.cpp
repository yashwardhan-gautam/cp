#include<bits/stdc++.h>
using namespace std;
bool check(string s,int i)
{
	if(i+2<s.size() and s[i]=='W' and s[i+1]=='U' and s[i+2]=='B') return true;
	return false;
}
int main()
{
	string s;	cin>>s;
	while(s.find("WUB")==0)	s.erase(0,3);
	reverse(s.begin(),s.end());
	while(s.find("BUW")==0) s.erase(0,3);
	reverse(s.begin(),s.end());
	//cout<<s<<"\n";
	string ans;
	for(int i=0;i<s.size();)
	{
		while(!check(s,i) and i<s.size()) 
		{
			//cout<<"first while loop"<<s[i]<<"\n";
			ans+=s[i];
			i++;
		}
		ans+=" ";
		while(check(s,i) and i<s.size())
		{
			//cout<<"second while loop"<<s[i]<<"\n";
			 i+=3;
		}
	}
	reverse(ans.begin(),ans.end());
	string ans1;
	int index=0;
	while(ans[index]==' ') index++;
	for(int i=index;i<ans.size();i++)	ans1+=ans[i];
	reverse(ans1.begin(),ans1.end());
	cout<<ans1<<"\n";
	//cout<<ans1.size()<<"\n";
	return 0;
}
