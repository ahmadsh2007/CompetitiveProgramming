#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ayham(int isco)
{
 int n;cin>>n;
 bool pos=0,neg=0;
 for(int i=0;i<n;i++)
 {
  int x;cin>>x;
  if(x<0)
  neg=1;
  else if(x>0)
  pos=1;
 }
 cout<<neg+pos<<"\n";



}
int main() 
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("hanya.in", "r", stdin);
  int t=1;
   cin>>t;

  while(t--)
  {
    ayham(22);
  }
    return 0;
}