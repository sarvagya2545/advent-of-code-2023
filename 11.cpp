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

vector<int> expand(vector<int> v) {
    vector<int> newV;
    for(int x : v) {
        if(x == 0) {
            newV.push_back(x);
            newV.push_back(x);
        } else {
            newV.push_back(x);
        }
    }

    return newV;
}

ll sum(vector<int> arr) {
    ll cnt = 0, s = 0;
    ll ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) {
            ans += (cnt * i - s) * arr[i];
            s += i * arr[i];
            cnt += arr[i];
        }
    }

    return ans;
}

ll solvePart1(vector<string> &image) {
    int m = image.size(), n = image[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(image[i][j] == '#') {
                row[i]++;
                col[j]++;
            }
        }
    }

    debug(row)
    debug(col)

    row = expand(row);
    col = expand(col);

    debug(row)
    debug(col)

    ll sum_row = sum(row), sum_col = sum(col);
    debug(sum_row)
    debug(sum_col)
    return sum_row + sum_col;
}

ull sum2(vector<int> arr) {
    ull sumOfDistances = 0, cnt = 0;
    ull ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        ans += sumOfDistances * arr[i];
        if(arr[i] > 0) {
            cnt += arr[i];
            sumOfDistances += cnt;
        } else {
            sumOfDistances += cnt * 1e6;
        }
    }

    return ans;
}

ll solvePart2(vector<string> &image) {
    int m = image.size(), n = image[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(image[i][j] == '#') {
                row[i]++;
                col[j]++;
            }
        }
    }

    ll sum_row = sum2(row), sum_col = sum2(col);
    return sum_row + sum_col;
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
    vector<string> image;
    while(getline(cin, line)) {
        image.push_back(line);
    }

    cout << solvePart1(image) << "\n";
    cout << solvePart2(image) << "\n";

    return 0;
}