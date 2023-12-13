#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " "; __print(x); cerr << endl;
#else
    #define debug(x) 
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ull x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << x;}
void __print(string x) {cerr << x;}
void __print(bool x) {cerr << x;}
template<class T> void __print(vector<T> x) {cerr << "[ "; for(T i: x) {__print(i); cerr << " "; } cerr << " ]";}
template<class T> void __print(set<T> x) {cerr << "[ "; for(T i: x) { __print(i); cerr << " "; } cerr << "]";}
template<class T, class U> void __print(pair<T, U> x) {cerr << "{ "; __print(x.ff); cerr << ", "; __print(x.ss); cerr << " }";}
template<class T, class V> void __print(map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void __print(unordered_map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}

bool isDigit(char c) {
    return c <= '9' and c >= '0';
}

int to_num(string num) {
    int x = 0;
    for(char c: num) {
        if(not isDigit(c)) return -1;
        x = x * 10 + (c - '0');
    }
    return x;
}

vector<int> getNumList(vector<string> v) {
    vector<int> ans;
    for(string s: v) {
        ans.push_back(to_num(s));
    }

    return ans;
}

vector<string> tokenize(string line, char delimiter) {
    stringstream s(line);
    string token;
    vector<string> tokens;

    while(getline(s, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

// int tc = 1;
// int solve(string line) {
//     string springs = line.substr(0, line.find(' '));
//     vector<int> vals = getNumList(tokenize(line.substr(line.find(' ') + 1), ','));
//     int n = springs.size(), m = vals.size();
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
//     debug(springs)
//     debug(vals)

//     // f(i, j)
//     // = f(i + 1, j) if springs[i] == '.'
//     // = f(i + vals[j], j + 1) if springs[i] == '#' and springs[i:i + vals[j] - 1] contains only '#' or '?'
//     // = f(i + 1, j) + (f(i + vals[j], j + 1) if possible or 0) if springs[i] == '?'

//     // f(n, m) = 1
//     // f(i, m) = f(i + 1, m) if springs[i] != '#' else 0
//     // f(n, j) = 0 (for j < m)

//     // ans = f(0,0)

//     vector<int> prefixDotCnt(n + 1, 0);
//     for(int i = 0; i < n; i++) {
//         prefixDotCnt[i + 1] = prefixDotCnt[i] + ((springs[i] == '.') ? 1 : 0);
//     }
//     debug(prefixDotCnt)

//     dp[n][m] = 1;

//     for(int i = n - 1; i >= 0; i--) {
//         for(int j = m; j >= 0; j--) {
//             if(springs[i] == '.') {
//                 dp[i][j] = dp[i + 1][j];
//             } else if(springs[i] == '#') {
//                 if(j < m and i + vals[j] <= n and prefixDotCnt[i + vals[j]] - prefixDotCnt[i] == 0) {
//                     if(i + vals[j] < n and vals[i + vals[j]] != '#') {
//                         dp[i][j] = dp[i + vals[j] + 1][j + 1];
//                     } else if(i + vals[j] == n) {
//                         dp[i][j] = dp[n][j + 1];
//                     }
//                 }
//             } else if(springs[i] == '?') {
//                 dp[i][j] = dp[i + 1][j];

//                 if(j < m and i + vals[j] <= n and prefixDotCnt[i + vals[j]] - prefixDotCnt[i] == 0) {
//                     if(i + vals[j] < n and vals[i + vals[j]] != '#') {
//                         dp[i][j] += dp[i + vals[j] + 1][j + 1];
//                     } else if(i + vals[j] == n) {
//                         dp[i][j] += dp[n][j + 1];
//                     }
//                 }
//             }
//         }
//     }

//     if (tc == 1) {
//         debug(dp)
//     }
//     tc++;
//     return dp[0][0];
// }

ull solve(string springs, vector<int> vals, int n, int m) {

    debug(springs)
    debug(vals)

    // map<int,int> dp[n + 1][m + 1];
    vector<vector<map<int,ull>>> dp(n + 1, vector<map<int,ull>>(m + 1));
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = map<int,ull>();

    function<ull(string&, vector<int>&, int,int,int)> helper;
    helper = [&](string &springs, vector<int> &vals, int i, int j, int use) -> ull {
        if(i == n) {
            if(j < m and vals[j] == use) {
                j++;
            }

            if(j == m) return 1;
            else return 0;
        }

        if(j == m) {
            if(springs[i] != '#') {
                return helper(springs, vals, i + 1, j, use);
            } else {
                return 0;
            }
        }

        if(dp[i][j].count(use)) {
            return dp[i][j][use];
        }

        // debug(i)
        // debug(j)

        ull ans = 0;
        if(springs[i] == '.' || springs[i] == '?') {

            if(use == vals[j]) {
                ans += helper(springs, vals, i + 1, j + 1, 0);
            } else if(use == 0) {
                ans += helper(springs, vals, i + 1, j, 0);
            }
        }
        
        if(springs[i] == '#' || springs[i] == '?') {
            if(use < vals[j]) {
                ans += helper(springs, vals, i + 1, j, use + 1);
            }
        }

        return dp[i][j][use] = ans;
        return ans;
    };

    return helper(springs, vals, 0, 0, 0);
}

int main()
{
    // Fast Input & Output
    fastio();
    cout << boolalpha; // to show true / false instead of 1 / 0
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #endif

    string line;
    int tot = 0;
    ull tot2 = 0;
    while(getline(cin, line)) {
        string springs = line.substr(0, line.find(' '));
        vector<int> vals = getNumList(tokenize(line.substr(line.find(' ') + 1), ','));
        int n = springs.size(), m = vals.size();

        string newSprings = "";
        vector<int> newVals;

        for(int i = 1; i <= 5; i++) {
            newSprings += springs;
            if(i < 5) newSprings += '?';

            for(int x: vals) newVals.push_back(x);
        }

        int x = solve(springs, vals, n, m);
        ull x2 = solve(newSprings, newVals, (int)newSprings.size(), (int)newVals.size());
        debug(x)
        tot += x;
        tot2 += x2;
    }
    cout << tot << "\n";
    cout << tot2 << "\n";

    return 0;
}