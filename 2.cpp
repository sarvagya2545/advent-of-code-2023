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

int parseInt(string num) {
    // debug(num)
    int x = 0;
    for(char d: num) {
        x = x * 10 + (d - '0');
    }

    return x;
}

bool isPossible(string line) {
    line.erase(0, line.find(": ") + 2);
    string color = "", num = "";
    line += ";";
    debug(line)

    int b = 0, g = 0, r = 0;
    for(char c: line) {
        if(c == ' ') continue;
        if(c == ',' || c == ';') {
            int x = parseInt(num);
            debug(color)
            debug(x)
            if(color == "green") {
                g = max(g, x);
            } else if(color == "blue") {
                b = max(b, x);
            } else {
                r = max(r, x);
            }

            num = "";
            color = "";
            continue;
        }

        if(c <= '9' and c >= '0') {
            num += c;
        } else {
            color += c;
        }
    }

    return (b <= 14 and g <= 13 and r <= 12);
}

// Part 2
int powerOfCubes(string line) {
    line.erase(0, line.find(": ") + 2);
    string color = "", num = "";
    line += ";";
    // debug(line)

    int b = 0, g = 0, r = 0;
    for(char c: line) {
        if(c == ' ') continue;
        if(c == ',' || c == ';') {
            int x = parseInt(num);
            // debug(color)
            // debug(x)
            if(color == "green") {
                g = max(g, x);
            } else if(color == "blue") {
                b = max(b, x);
            } else {
                r = max(r, x);
            }

            num = "";
            color = "";
            continue;
        }

        if(c <= '9' and c >= '0') {
            num += c;
        } else {
            color += c;
        }
    }

    return b * g * r;
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
    long long sum = 0;
    int id = 1;
    while(getline(cin, line)) {
        int x = powerOfCubes(line);
        sum += x;
    }

    cout << sum << "\n";

    return 0;
}