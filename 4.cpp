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

vector<string> tokenize(string line, char delimiter) {
    stringstream s(line);
    string token;
    vector<string> tokens;

    while(getline(s, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

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

int score(string line) {
    line = line.substr(line.find(":") + 1);
    string winningNumberString = line.substr(0, line.find("|"));
    string numbersInHandString = line.substr(line.find("|") + 1);
    vector<string> winningNumbers = tokenize(winningNumberString, ' ');
    vector<string> numbersInHand = tokenize(numbersInHandString, ' ');
    set<int> winningNumberSet;

    for(string num: winningNumbers) {
        if(num == "") continue;
        int x = to_num(num);
        winningNumberSet.insert(x);
    }

    int res = 1;
    for(string num: numbersInHand) {
        if(num == "") continue;
        int x = to_num(num);

        if(winningNumberSet.count(x)) {
            res *= 2;
        }
    }

    return res / 2;
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
    int total = 0;
    while(getline(cin, line)) {
        int cardPointValue = score(line);
        debug(cardPointValue)
        total += cardPointValue;
    }

    cout << total;

    return 0;
}