![Codeforces Badge](https://img.shields.io/badge/Codeforces-ahmadsh2007-red?style=flat-square)
![CF Rating](https://img.shields.io/badge/dynamic/json?style=flat-square&color=blue&label=CF%20Rating&query=%24.result[0].rating&url=https://codeforces.com/api/user.info?handles=ahmadsh2007)
![GitHub last commit](https://img.shields.io/github/last-commit/ahmadsh2007/CompetitiveProgramming?style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/ahmadsh2007/CompetitiveProgramming?style=flat-square)
![GitHub repo size](https://img.shields.io/github/repo-size/ahmadsh2007/CompetitiveProgramming?style=flat-square)
![C++](https://img.shields.io/badge/C++-17/20/23-blue?style=flat-square&logo=c%2B%2B)
![License](https://img.shields.io/github/license/ahmadsh2007/CompetitiveProgramming?style=flat-square)

# Competitive Programming Repository

Welcome to my Competitive Programming (CP) repository! This repository is structured to help me efficiently solve problems and practice algorithms across multiple platforms and contests.

## Codeforces Stats

![Codeforces Stats](https://codeforces-readme-stats.vercel.app/api/card?username=ahmadsh2007&theme=default)

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

**macOS / Linux**

```json
"code-runner.executorMap": {
  "cpp": "cd $dir && mkdir -p bin && g++ $fileName -I$workspaceRoot/Utils -o bin/$fileNameWithoutExt && bin/$fileNameWithoutExt"
}
```

**Windows (PowerShell)**

```json
"code-runner.executorMap": {
  "cpp": "cd $dir; if (!(Test-Path bin)) { New-Item -ItemType Directory -Path bin | Out-Null }; g++ $fileName -I$workspaceRoot/Utils -o bin/$fileNameWithoutExt; ./bin/$fileNameWithoutExt"
}
```


* ONLINE_JUDGE mode reads from `Utils/input.txt` and writes to `Utils/output.txt`.

## Contributing

If you have better solutions, submit them with your name, Codeforces username, and GitHub username. If you have quality improvements for the overall design of the repo, better utilities, file management, or anything else, feel free to submit them as well.
