#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ayham(int isco)
{
 ll n,k;cin>>n>>k;
 ll x=n*k;
 if(k%2)
 {
  if(n%2)
  {
    cout<<"Omda\n";
  }
  else
  cout<<"Teemo\n";
 }
 else 
 {
  if((x%(k+1))%2==1||x%(k+1)==k)
  {
   cout<<"Omda\n";
  }
  else
  cout<<"Teemo\n";
 }
}
int main() 
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("dotak.in", "r", stdin);
  int t=1;
   cin>>t;

  while(t--)
  {
    ayham(22);
  }
    return 0;
}