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
}