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

bool dividesIntoMirror(vector<ll> &v, int i) {
    int l = i, r = i + 1;
    int n = v.size();
    while(l >= 0 and r < n) {
        if(v[l] != v[r]) {
            return false;
        }

        l--;
        r++;
    }

    return true;
}

int solvePart1(vector<string> &patch) {
    int m = patch.size(), n = patch[0].size();
    vector<ll> rowEncoding(m, 0LL), colEncoding(n, 0LL);
    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(patch[row][col] == '#') {
                rowEncoding[row] |= (1LL << col);
                colEncoding[col] |= (1LL << row);
            }
        }
    }

    int ans = 0;

    for(int row = 0; row < m - 1; row++) {
        if(dividesIntoMirror(rowEncoding, row)) {
            ans += 100 * (row + 1);
        }
    }

    for(int col = 0; col < n - 1; col++) {
        if(dividesIntoMirror(colEncoding, col)) {
            ans += col + 1;
        }
    }

    return ans;
}

int changesToDivideByMirror(vector<ll> &v, int i) {
    int l = i, r = i + 1;
    int n = v.size();

    int changes = 0;
    while(l >= 0 and r < n) {
        changes += __builtin_popcount(v[l] ^ v[r]);
        l--;
        r++;
    }

    return changes;
}

int solvePart2(vector<string> &patch) {
    int m = patch.size(), n = patch[0].size();
    vector<ll> rowEncoding(m, 0LL), colEncoding(n, 0LL);
    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(patch[row][col] == '#') {
                rowEncoding[row] |= (1LL << col);
                colEncoding[col] |= (1LL << row);
            }
        }
    }

    int ans = 0;

    for(int row = 0; row < m - 1; row++) {
        if(changesToDivideByMirror(rowEncoding, row) == 1) {
            ans += 100 * (row + 1);
        }
    }

    for(int col = 0; col < n - 1; col++) {
        if(changesToDivideByMirror(colEncoding, col) == 1) {
            ans += col + 1;
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
    vector<string> patch;
    int ans = 0, ans2 = 0;

    while(getline(cin, line)) {
        if(line == "") {
            int x = solvePart1(patch);
            int y = solvePart2(patch);
            ans += x;
            ans2 += y;
            patch.clear();
        } else {
            patch.push_back(line);
        }
    }

    ans += solvePart1(patch);
    ans2 += solvePart2(patch);
    cout << ans << "\n";
    cout << ans2 << "\n";

    return 0;
}