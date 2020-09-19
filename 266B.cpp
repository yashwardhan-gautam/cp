#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;	cin>>n>>k;
	string s;	cin>>s;
	for(int i=0;i<k;i++)
	{
		for(int i=0;i<n-1;i++)
		{
			if(s[i]=='B' and s[i+1]=='G')
			{
				swap(s[i],s[i+1]);
				i++;
			}
		}
		//cout<<s<<"\n";
	}
	//cout<<endl;
	cout<<s<<"\n";
	return 0;
}
