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

ll to_num(string num) {
    int neg = 0;
    if(num[0] == '-') {
        neg = 1;
        num = num.substr(1);
    }

    ll x = 0;
    for(char c: num) {
        if(not isDigit(c)) return -1;
        x = x * 10 + (c - '0');
    }

    if(neg == 1) x = -x;
    return x;
}

vector<ll> parse(string line) {
    stringstream s(line);
    string num;
    vector<ll> v;
    while(getline(s, num, ' ')) {
        ll x = to_num(num);
        v.pb(x);
    }

    return v;
}

ll solve(vector<ll> &v, int n) {
    int f = 1;
    for(int i = 0; i < n; i++) {
        if(v[i] != 0ll) {
            f = 0;
            break;
        }
    }

    if(f) {
        return 0ll;
    }


    for(int i = 1; i < n; i++) {
        v[i - 1] = v[i] - v[i - 1];
    }

    ll next = solve(v, n - 1);

    for(int i = n - 1; i >= 1; i--) {
        v[i - 1] = v[i] - v[i - 1];
    }

    return next + v[n - 1];
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
    ll sumPart1 = 0ll;
    ll sumPart2 = 0ll;
    while(getline(cin, line)) {
        vector<ll> v = parse(line);
        ll next = solve(v, (int)v.size());

        vector<ll> v2 = vector<ll>(v.rbegin(), v.rend());
        ll next2 = solve(v2, (int)v2.size());

        sumPart1 += next;
        sumPart2 += next2;
    }

    cout << sumPart1 << "\n";
    cout << sumPart2 << "\n";

    return 0;
}