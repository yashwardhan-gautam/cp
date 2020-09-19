#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n;	cin>>n;
	if(n>0)	cout<<n<<"\n";
	else 
	{
		n=-1*n;
		string s=to_string(n);
		string temp=s;
		temp.erase(temp.begin()+temp.size()-1);
		string s1=temp;
		temp=s;
		temp.erase(temp.begin()+temp.size()-2);
		string s2=temp;
		int n1=-1*stoi(s1);
		int n2=-1*stoi(s2);
		//cout<<s1<<" "<<s2<<" "<<n1<<" "<<n2<<"\n";
		cout<<max(n1,n2)<<"\n";
	}
	return 0;
}
