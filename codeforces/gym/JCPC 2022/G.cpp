#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n, q;
  cin >> n >> q;

  vector<ll> v(n);

  for (auto &it : v)
    cin >> it;

  int mxRight = *max_element(v.begin(), v.end());
  int mnLeft = *min_element(v.begin(), v.end());

  vector<pair<int, int>> check(n);

  for (int i = 0; i < n; ++i)
    check[i] = make_pair(v[i], i);

  sort(check.begin(), check.end());

  vector<int> mnInd(n), mxInd(n);
  mxInd[0] = check[0].second;
  mnInd[n - 1] = check[n - 1].second;

  for (int i = 1; i < n; ++i)
  {
    mxInd[i] = max(mxInd[i - 1], check[i].second);
  }

  for (int i = n - 2; i >= 0; --i)
  {
    mnInd[i] = min(mnInd[i + 1], check[i].second);
  }

  // for (auto &it : mxInd)
  //   cout << it << ' ';

  // cout << endl;

  // for (auto &it : mnInd)
  //   cout << it << ' ';
  // cout << endl;

  while (q--)
  {
    int x, y;
    cin >> x >> y;

    if (x > mxRight or y > mxRight)
    {
      cout << "NO\n";
    }
    else if (x <= y)
    {
      cout << "YES\n";
    }
    else if (y < mnLeft)
    {
      cout << "NO\n";
    }
    else
    {
      // x -> y where x > y

      int ind = lower_bound(check.begin(), check.end(), make_pair(y, -1)) - check.begin();

      if (check[ind].first > y)
        ind--;

      int ind2 = upper_bound(check.begin(), check.end(), make_pair(x, -1)) - check.begin();

      if (mxInd[ind] >= mnInd[ind2])
      {
        cout << "YES\n";
      }
      else
        cout << "NO\n";
    }
  }
}

int main()
{
  freopen("milk.in", "r", stdin);
  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }
}