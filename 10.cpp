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
template<class T, class U> void __print(pair<T, U> x) {cerr << "{ "; __print(x.ff); cerr << ", "; __print(x.ss); cerr << " }";}
template<class T> void __print(queue<T> x) {cerr << "[ "; for(T i: x) {__print(i); cerr << " "; } cerr << " ]";}
template<class T> void __print(set<T> x) {cerr << "[ "; for(T i: x) { __print(i); cerr << " "; } cerr << "]";}
template<class T, class V> void __print(map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void __print(unordered_map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}

int m, n;
bool exists(int y, int x) {
    return (y >= 0 and y < m) and (x >= 0 and x < n);
}

vector<vector<int>> solve(vector<string> &grid) {
    m = grid.size(), n = grid[0].size();
    debug(m)
    debug(n)
    int x, y;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'S') {
                y = i;
                x = j;
                break;
            }
        }
    }

    queue<pair<int,int>> Q;
    vector<vector<int>> visited(m, vector<int> (n, 0));

    if(x + 1 < n) {
        if(grid[y][x + 1] == 'J' or grid[y][x + 1] == '7' or grid[y][x + 1] == '-') {
            Q.push({ y, x + 1 });
            visited[y][ x + 1] = 1;
        }
    }
    if(x - 1 >= 0) {
        if(grid[y][x - 1] == 'L' or grid[y][x - 1] == 'F' or grid[y][x - 1] == '-') {
            Q.push({ y, x - 1 });
            visited[y][ x - 1] = 1;
        }
    }
    if(y + 1 < m) {
        if(grid[y + 1][x] == 'F' or grid[y + 1][x] == '7' or grid[y + 1][x] == '|') {
            Q.push({ y + 1, x });
            visited[y + 1][ x] = 1;
        }
    }
    if(y -  1 < n) {
        if(grid[y - 1][x] == 'J' or grid[y - 1][x] == 'L' or grid[y - 1][x] == '|') {
            Q.push({ y - 1, x });
            visited[y - 1][ x] = 1;
        }
    }

    // debug((int)Q.size());

    int dist = 2;

    int q = 0;
    while(!Q.empty()) {
        int items = Q.size();
        int p = 0;
        // q++;
        // if(q >= 1e3) {
        //     debug((int)Q.size());
        //     break;
        // }
        while(items--) {
            // p++;
            // if(p >= 1e6) break;
            auto [y,x] = Q.front();
            Q.pop();
            char c = grid[y][x];
            vector<pair<int,int>> next;
            if(c == '7') {
                if(exists(y, x - 1) and !visited[y][x - 1] and grid[y][x - 1] != '.' and grid[y][x - 1] != 'S') {
                    next.push_back({ y, x - 1 });
                }
                if(exists(y - 1, x) and !visited[y - 1][x] and grid[y - 1][x] != '.' and grid[y - 1][x] != 'S') {
                    next.push_back({ y - 1, x });
                }
            } else if(c == 'L') {
                if(exists(y, x + 1) and !visited[y][x + 1] and grid[y][x + 1] != '.' and grid[y][x + 1] != 'S') {
                    next.push_back({ y, x + 1 });
                }
                if(exists(y + 1, x) and !visited[y + 1][x] and grid[y + 1][x] != '.' and grid[y + 1][x] != 'S') {
                    next.push_back({ y + 1, x });
                }
            } else if(c == 'F') {
                if(exists(y, x + 1) and !visited[y][x + 1] and grid[y][x + 1] != '.' and grid[y][x + 1] != 'S') {
                    next.push_back({ y, x + 1 });
                }
                if(exists(y - 1, x) and !visited[y - 1][x] and grid[y - 1][x] != '.' and grid[y - 1][x] != 'S') {
                    next.push_back({ y - 1, x });
                }
            } else if(c == 'J') {
                if(exists(y, x - 1) and !visited[y][x - 1] and grid[y][x - 1] != '.' and grid[y][x - 1] != 'S') {
                    next.push_back({ y, x - 1 });
                }
                if(exists(y + 1, x) and !visited[y + 1][x] and grid[y + 1][x] != '.' and grid[y + 1][x] != 'S') {
                    next.push_back({ y + 1, x });
                }
            } else if(c == '|') {
                if(exists(y + 1, x) and !visited[y + 1][x] and grid[y + 1][x] != '.' and grid[y + 1][x] != 'S') {
                    next.push_back({ y + 1, x });
                }
                if(exists(y - 1, x) and !visited[y - 1][x] and grid[y - 1][x] != '.' and grid[y - 1][x] != 'S') {
                    next.push_back({ y - 1, x });
                }
            } else if(c == '-') {
                if(exists(y, x - 1) and !visited[y][x - 1] and grid[y][x - 1] != '.' and grid[y][x - 1] != 'S') {
                    next.push_back({ y, x - 1 });
                }
                if(exists(y, x + 1) and !visited[y][x + 1] and grid[y][x + 1] != '.' and grid[y][x + 1] != 'S') {
                    next.push_back({ y, x + 1 });
                }
            } else {
                continue;
            }

            for(auto [_y, _x] : next) {
                Q.push({ _y, _x });
                visited[_y][_x] = dist;
            }
        }

        dist++;
    }

    debug(visited)

    int mx = 0;
    for(auto v: visited) {
        mx = max(mx, *max_element(v.begin(), v.end()));
    }

    visited[y][x] = -1;

    cout << mx << "\n";
    return visited;
}

void solvePart2(vector<string> &grid, vector<vector<int>> &visited) {
    for(auto &v: visited) {
        for(auto &u: v) {
            if(u != 0) {
                u = 1;
            }
        }
    }

    int m = visited.size(), n = visited[0].size();

    debug(visited)
    for(string &s: grid) {
        for(char &v: s) {
            if(v == 'S') {
                v = '|';
            }
        }
    }
    int cnt = 0;
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(visited[r][c] == 1) continue;
            int pr = 0, pc = 0;
            for(int i = 0; i < c; i++) {
                if(visited[r][i] == 1 and (
                    grid[r][i] == '|' || 
                    grid[r][i] == 'J' || 
                    grid[r][i] == 'L'
                )) pr++;
            }

            // for(int i = 0; i < c; i++) {
            //     if(visited[r][i] == 1 and grid[r][i] != '-') pc++;
            // }

            // debug(r)
            // debug(c)
            // debug(grid[r][c])
            // debug(pr)
            // debug(pc)

            if(pr % 2 == 1) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

/*
..........
.L--JL--J.
.|II||II|.
.|L-7F-J|.
.||OOOO||.
.||OOOO||.
.|F----7|.
.S------7.
..........
*/

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

    reverse(grid.begin(), grid.end());
    debug(grid);
    auto visited = solve(grid);

    solvePart2(grid, visited);

    return 0;
}