
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
  int b, d, c, k, t;
  cin >> b >> d >> c >> k >> t;

  for (int i = 1; i <= t; ++i)
  {
    b -= d;
    b = max(0LL, b);

    if (b == 0)
      break;

    if (i % k == 0)
    {
      b += c;
      b = min(b, 100LL);
    }
  }

  cout << b;
}

int32_t main()
{
  FAST;
  int t = 1;
  // cin >> t;

  while (t--)
  {
    solve();
  }
}