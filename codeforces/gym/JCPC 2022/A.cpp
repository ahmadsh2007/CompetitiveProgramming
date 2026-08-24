#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;

  if (n <= 26)
  {
    cout << "Yes\n";
  }
  else
    cout << "No\n";
}

int main()
{
  freopen("Round1.in", "r", stdin);
  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }
}