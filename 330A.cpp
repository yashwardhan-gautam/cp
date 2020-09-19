#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,c;	cin>>r>>c;
	char mat[r][c];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)	cin>>mat[i][j];
	}
	bool mark[r][c];
	memset(mark,0,sizeof(mark));
	//checking for rows
	for(int i=0;i<r;i++)
	{
		int flag=0;
		for(int j=0;j<c;j++)
		{
			if(mat[i][j]=='S')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(int j=0;j<c;j++)
				mark[i][j]=1;
		}
	}
	//checking for columns
	for(int j=0;j<c;j++)
	{
		int flag=0;
		for(int i=0;i<r;i++)
		{
			if(mat[i][j]=='S')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(int i=0;i<r;i++)
			{
				mark[i][j]=1;
			}
		}
	}
	int ans=0;
	//all those position which are marked can be eaten by cakeminator
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			//cout<<mark[i][j]<<" ";	cout<<endl;
		if(mark[i][j])	ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
