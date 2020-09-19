#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;	cin>>n>>m;
	string mat[n];
	for(int i=0;i<n;i++)
		cin>>mat[i];
	unordered_set<char> s;
	for(int j=0;j<m;j++)
	{
		int index=0;
		for(int i=0;i<n;i++)
		{
			if(mat[i][j]>=mat[index][j])
			{
				index=i;
			}
		}
		//cout<<mat[index][j]<<" \n";
		for(int i=0;i<n;i++)
		{
			if(mat[i][j]==mat[index][j])
			{
				if(s.find(i)==s.end())	s.insert(i);
			}
		}
	}
	cout<<s.size()<<"\n";
	return 0;
}
