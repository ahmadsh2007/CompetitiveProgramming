# Competitive Programming Repository

Welcome to my Competitive Programming (CP) repository! This repository is structured to help me efficiently solve problems and practice algorithms across multiple platforms and contests.

## Repository Structure

```
CompetitiveProgramming/
├─ JUST ACM/
│  ├─ Templates/
│  ├─ 2024 Training - Beginner
│  ├─ 2025 Training - Junior
│  └─ 2026 Training - Beginner
├─ Utils/
│  ├─ debug.h
│  ├─ input.txt
│  └─ output.txt
├─ codeforces/
│  └─ YYYY/
│     └─ ContestName/          
├─ helper.py
├─ cp_commit.py
└─ README.md
```

## CP Template

This is the template I use for all my C++ solutions:

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "Utils/debug.h" // adjust the path if necessary
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    // Your solution here
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
        // ! adjust depth if necessary
        freopen("Utils/input.txt", "r", stdin);
        freopen("Utils/output.txt", "w", stdout);
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
```

## Usage

1. Place `input.txt` and `output.txt` in the `Utils` folder.
2. Write your solution in any `.cpp` file.
3. Compile and run; the executable will be generated in the `bin/` folder.

### VS Code Integration

* `settings.json` ensures all C++ executables are created in `bin/` and includes the `Utils` folder for headers:

```json
"code-runner.executorMap": {
  "cpp": "cd $dir && mkdir -p bin && g++ $fileName -I$workspaceRoot/Utils -o bin/$fileNameWithoutExt && bin/$fileNameWithoutExt"
}
```

* ONLINE_JUDGE mode reads from `Utils/input.txt` and writes to `Utils/output.txt`.

## Contributing

If you have better solutions, submit them with your name, Codeforces username, and GitHub username. If you have quality improvements for the overall design of the repo, better utilities, file management, or anything else, feel free to submit them as well.