#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl      "\n"
void fast()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}
int n;  
vector<pair<int,string>> v;
vector<vector<int> > dp;
// at each index(juice) we have two choices
// op1 = skip that juice (no vitamins, no price paid).
// op2 = we drink that juice, gain the vitamins and add the price in expenses
int solve(int i,bool a,bool b,bool c) 
{
  //base case
  if (i==n) {
    // if we reach the last index and still not able to see all three characters
    if(!a or !b or !c) return INT_MAX;
    //otherwise
    return 0;
  }
  string s = v[i].second;
  int mask = 0;
  if(c) mask++;
  if(b) mask+=2;
  if(a) mask+=4;
  if(dp[i][mask]!=-1)
    return dp[i][mask];
  int op1 = 0 + solve(i+1,a,b,c);
  if(s.find('A')!=string::npos) a=a||1;
  if(s.find('B')!=string::npos) b=b||1;
  if(s.find('C')!=string::npos) c=c||1; 
  int op2 = v[i].first + solve(i+1,a,b,c);
  return dp[i][mask]=min(op1,op2);
}
int32_t main()
{
  fast();
  cin>>n;
  bool gota=false,gotb=false,gotc=false;
  for(int i=0;i<n;i++)
  {
    int x;  string s; cin>>x>>s;
    v.pb({x,s});
    if(!gota && s.find('A')!=string::npos) gota=true;
    if(!gotb && s.find('B')!=string::npos) gotb=true;
    if(!gotc && s.find('C')!=string::npos) gotc=true; 
  }
  if(!gota or !gotb or !gotc) {
    cout<<"-1";
    return 0;
  }
  dp.resize(n+1,vector<int>(8,-1));
  bool a=0,b=0,c=0;
  int ans = solve(0,a,b,c);
  if(ans==INT_MAX)
    cout<<"-1";
  else 
    cout<<ans;
}