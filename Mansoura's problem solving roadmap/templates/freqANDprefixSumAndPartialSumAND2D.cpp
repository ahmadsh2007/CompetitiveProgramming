#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int n = 10;

int main()
{
    // * They are mainly four types of Frequency Arrays
    // 1- Array of Numbers,                     Freq[arr[i]]++;
    // 2- Array of Characters (string),         Freq[s[i] - 97]++;  || Freq[s[i] - 65]++;
    // 3- Array of Characters (string),         Freq[s[i] - 'a']++; || Freq[s[i] - 'A']++;
    // 4- String of Digits,                     Freq[s[i] - '0']++;


    // ! There are multiple types of prefix
    // * Such like the OG one, prefix sum
    // * there is also prefix max:
    ll array[n] = {};
    ll prefixMax[n] = {};
    for (int i = 0; i < n; i++) prefixMax[i] = max(prefixMax[i - 1], array[i]);

    // * there is also prefix min:
    ll array[n] = {};
    ll prefixMax[n] = {};
    for (int i = 0; i < n; i++) prefixMax[i] = min(prefixMax[i - 1], array[i]);


    // ! 2D PrefixSum
    int size = 1005;
    int arr[size][size];
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[j][i] += arr[j - 1][i];
        }
    }

    int up, left, down, right; cin >> up >> left >> down >> right;
    cout << arr[down][right] - arr[up - 1][right] - arr[down][left - 1] + arr[up - 1][left - 1];

    /*
        Try input this, and the result must be 27:
        4 4
        6 7 8 9
        5 4 2 3
        4 7 8 3
        5 3 3 3
        2 2
        3 4
    */

    // * Recap 2D PrefixSum steps
    // Step 1: Make an 2D array for prefix
    // Step 2: PrefixSum for each row
    // Step 3: PrefixSum for each column
    // Step 4: Calculate the Answer,
    //         Answer = pre[Down][Right]   - pre[Down][Left - 1]
    //                - pre[Up - 1][Right] + pre[Up - 1][Left - 1]
}