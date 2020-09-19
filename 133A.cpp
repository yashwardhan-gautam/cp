//since we are supposed to check if the program will print 
//anything or not, it's sufficient to check if it contains H,Q or 9
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='H' or s[i]=='Q' or s[i]=='9' )
		{
			flag=1;
			break;
		}
	}
	if(flag==1)	cout<<"YES\n";
	else 		cout<<"NO\n";
	return 0;
}
