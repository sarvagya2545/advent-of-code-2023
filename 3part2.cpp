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
    return c >= '0' and c <= '9';
}

int expand(string row, int pos) {
    string numString = row.substr(pos, 1);

    for(int left = pos - 1; left >= 0; left--) {
        if(isDigit(row[left])) {
            numString = (row[left]) + numString;
        } else {
            break;
        }
    }

    for(int right = pos + 1; right < row.size(); right++) {
        if(isDigit(row[right])) {
            numString += row[right];
        } else {
            break;
        }
    }

    int num = 0;
    for(char c: numString) {
        num = num * 10 + (c - '0');
    }

    return num;
}

// given that grid[row][col] = '*', find the gear ratio for this gear
int gearRatio(vector<string> &grid, int row, int col) {
    vector<int> numbers; // stores the numbers adjacent to this symbol

    if(row - 1 >= 0) {
        if(isDigit(grid[row - 1][col])) {
            numbers.push_back(expand(grid[row - 1], col));
        } else {
            if(isDigit(grid[row - 1][col - 1])) {
                numbers.push_back(expand(grid[row - 1], col - 1));
            }
            if(isDigit(grid[row - 1][col + 1])) {
                numbers.push_back(expand(grid[row - 1], col + 1));
            }
        }
    }

    if(row + 1 < grid.size()) {
        if(isDigit(grid[row + 1][col])) {
            numbers.push_back(expand(grid[row + 1], col));
        } else {
            if(isDigit(grid[row + 1][col - 1])) {
                numbers.push_back(expand(grid[row + 1], col - 1));
            }
            if(isDigit(grid[row + 1][col + 1])) {
                numbers.push_back(expand(grid[row + 1], col + 1));
            }
        }
    }

    if(isDigit(grid[row][col - 1])) {
        numbers.push_back(expand(grid[row], col - 1));
    }

    if(isDigit(grid[row][col + 1])) {
        numbers.push_back(expand(grid[row], col + 1));
    }

    if(numbers.size() != 2) {
        return 0;
    }

    return numbers[0] * numbers[1];
}

int solve(vector<string> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int ans = 0;
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(grid[row][col] == '*') {
                ans += gearRatio(grid, row, col);
            }
        }
    }

    return ans;
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
    vector<string> grid;
    while(getline(cin, line)) {
        grid.push_back(line);
    }

    cout << solve(grid);

    return 0;
}