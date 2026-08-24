#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void ayham(int isco)
{
  ll n,l,r;cin>>n>>l>>r;
  ll ans=0;
  for(ll d=1;d<=r;d++)
  {
    ll lx=max(l,d);
    ll rx=r;

    if(rx>=lx)
    {
      ans+=((n-lx)/d)-((n-rx-1)/d);
    }
  }
  cout<<ans<<"\n";
}
int main() 
{  
  int t=1;
  cin>>t;
  while(t--)
  {
    ayham(22);
  }
    return 0;
}