#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int mat[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)	cin>>mat[i][j];
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<3;j++)
		{
			if(mat[i][j])	count++;
			if(count>=2)	break;
		}
		if(count>=2)	ans++;
	}
	cout<<ans;
	return 0;
}
