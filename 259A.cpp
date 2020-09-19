#include<bits/stdc++.h>
using namespace std;
int main()
{
	char mat[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)	cin>>mat[i][j];
	
	int flag=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(mat[i][j]==mat[i][j+1])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)	break;
	}
	if(!flag)	cout<<"YES\n";
	else 		cout<<"NO\n"
	return 0;
}
