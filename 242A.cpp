#include<bits/stdc++.h>
using namespace std;
struct t
{
	int first;
	int second;
};
int main()
{
	int x,y,a,b;	cin>>x>>y>>a>>b;
	int count=0;
	vector<t> v;
	for(int c=a;c<=x;c++)
	{
		for(int d=b;d<=y and d<c;d++)
		{
			if(c+d<=x+y)
			{
				count=count+1;
				t temp;
				temp.first=c;
				temp.second=d;
				v.push_back(temp);
			}
		}
	}
	cout<<count<<"\n";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	return 0;
}
