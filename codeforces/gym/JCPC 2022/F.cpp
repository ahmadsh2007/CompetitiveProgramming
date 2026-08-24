#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string a, b;
  cin >> a >> b;

  if (a.length() < b.length())
    swap(a, b);

  string ans;
  int mx = 0;

  for (int i = 0; i < b.length(); ++i)
  {
    ans.push_back(b[i]);

    if (((a.length() % ans.length()) != 0) or ((b.length() % ans.length()) != 0))
      continue;

    string temp;
    for (int j = 0; j < (a.length() / ans.length()); ++j)
      temp += ans;

    if (temp != a)
      continue;

    temp.clear();

    for (int j = 0; j < (b.length() / ans.length()); ++j)
      temp += ans;

    if (temp != b)
      continue;

    mx = max(mx, (int)ans.length());
  }

  cout << mx << endl;
}

int main()
{
  freopen("sieve.in", "r", stdin);
  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }
}