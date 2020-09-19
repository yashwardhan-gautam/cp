#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool possible(vector<int> count,int k)
{
	for(int i=0;i<count.size();i++)
		if(count[i]!=0 and count[i]%k!=0)	return false;
	return true;
}
int32_t main()
{
	int k;	cin>>k;
	string s;	cin>>s;
	vector<int> count(26,0);
	for(int i=0;i<s.size();i++)	count[s[i]-'a']++;
	//for(int i=0;i<26;i++)	cout<<char(i+'a')<<" "<<count[i]<<"\n";
	if(k==1)	cout<<s<<"\n";
	else if(possible(count,k))
	{
		string ans;
		for(int t=0;t<k;t++)
		{
		for(int i=0;i<26;i++)
		{
			if(count[i])
			{
				for(int j=0;j<count[i]/k;j++)	ans+=(char)(i+'a');
			}
		}
		}
		cout<<ans<<"\n";		
	}
	else cout<<"-1\n";
	return 0;
}
