#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	char s[n];	
	for(int i=0;i<n;i++) cin>>s[i];
	stack<char> st;
	st.push(s[0]);
	for(int i=1;i<n;i++)
	{
		if(st.empty() or st.top()!=s[i])
		{
			//cout<<st.top()<<" "<<s[i]<<endl;
			st.push(s[i]);
		}
	}
	cout<<n-st.size();
	return 0;
}
