/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	vector<vector<char> > v;
	for(int i=0;i<=n;i++)
	{
		vector<char> temp;
		for(int j=0;j<(n-i);j++)	temp.push_back(' ');
		for(int k=0;k<=i;k++)	temp.push_back(char(k+'0'));
		for(int k=i-1;k>=0;k--)	temp.push_back(char(k+'0'));
		for(int j=0;j<(n-i);j++)	temp.push_back(' ');
		v.push_back(temp);
	}	
	//for(int i=0;i<v.size();i++)	cout<<v[i].size()<<" ";	cout<<"\n";
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)	cout<<v[i][j]<<" ";	cout<<"\n";
	}
	for(int i=v.size()-2;i>=0;i--)
	{
		for(int j=0;j<v[i].size();j++)	cout<<v[i][j]<<" ";	cout<<"\n";
	}
	return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	for(int i=0;i<=2*n;i++)
	{
		int max;
		if(i<=n)	max=i;
		else 		max=2*n-i;
		for(int j=n-max;j>0;j--)	cout<<"  ";
		for(int j=0;j<=max;j++)	cout<<j<<" ";
		for(int j=max-1;j>=0;j--)	cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}
*/

//Don't know why the above two codes are not working

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int row = -n; row <= n; ++row)
    {
        int top = n - abs(row);
        for (int i = 0; i < abs(row); ++i)
        {
            cout << "  ";
        }
        for (int i = 0; i < top; ++i)
        {
            cout << i << " ";
        }
        for (int i = top; i > 0; --i)
        {
            cout << i << " ";
        }
        cout << 0 << endl;
    }
    return 0;
}
