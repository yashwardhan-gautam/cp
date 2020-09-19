#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;	cin>>n>>m;
	string s;	
	if(n>=m)
	{
		for(int i=0;i<m;i++)	s+="BG";
		for(int j=0;j<n-m;j++)	s+="B";
	}
	else 
	{
		for(int j=0;j<n;j++)	s+="GB";
		for(int i=0;i<m-n;i++)	s+="G";
	}
	cout<<s<<"\n";
	return 0;
}
