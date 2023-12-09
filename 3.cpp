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

int solve(vector<string> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> marked(rows, vector<int> (cols, 0));

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(grid[row][col] != '.' and (not isDigit(grid[row][col]))) {
                for(int dx = -1; dx <= 1; dx++)
                    for(int dy = -1; dy <= 1; dy++)
                        if(row + dx < rows and row + dx >= 0)
                            if(col + dy < cols and col + dy >= 0)
                                marked[row + dx][col + dy] = 1;
            }
        }
    }

    debug(marked)

    int ans = 0;

    for(int row = 0; row < rows; row++) {
        string line = grid[row];
        int cur = 0, markedNum = 0;
        for(int col = 0; col < cols; col++) {
            char c = grid[row][col];

            if(isDigit(c)) {
                cur = cur * 10 + (c - '0');
                if(marked[row][col] == 1) {
                    markedNum = 1;
                }
            } else {
                if(markedNum) {
                    debug(cur)
                    ans += cur;
                }

                cur = 0;
                markedNum = 0;
            }
        }

        if(markedNum == 1 and isDigit(grid[row][cols - 1])) {
            ans += cur;
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