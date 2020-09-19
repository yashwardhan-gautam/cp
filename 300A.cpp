#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int arr[n];
	vector<int> v1,v2,v3;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(v1.size()==0 and arr[i]<0)	v1.push_back(arr[i]);
		else if(v2.size()==0 and arr[i]>0)	v2.push_back(arr[i]);
		else v3.push_back(arr[i]);  
	}
	if(v2.size()==0)
	{
		int flag=0;
		for(int i=0;i<v3.size();i++)
		{
			if(v3[i]<0)
			{
				v2.push_back(v3[i]);
				flag++;
			}
			if(flag==2)
				break;
		}
		
		for(int i=0;i<v2.size();i++)
		{
			for(int j=0;j<v3.size();j++)
			{
				if(v3[j]==v2[i])
				{
					v3.erase(v3.begin()+j);
					break;
				}
			}
		}
		
	}
	cout<<v1.size()<<" ";
	for(int i=0;i<v1.size();i++)	cout<<v1[i]<<" ";	cout<<"\n";
	
	cout<<v2.size()<<" ";
	for(int i=0;i<v2.size();i++)	cout<<v2[i]<<" ";	cout<<"\n";
	
	cout<<v3.size()<<" ";
	for(int i=0;i<v3.size();i++)	cout<<v3[i]<<" ";	cout<<"\n";
	return 0;
}
