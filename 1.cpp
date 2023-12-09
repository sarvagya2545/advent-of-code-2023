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

map<string, int> digitsInLetters = {
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine", 9}
};

pair<int,int> getFirstTextDigit(string line) {
    for(int i = 0; i < line.size(); i++) {
        string cur = "";
        for(int j = i; j < min(i + 5, (int)line.size()); j++) {
            cur = cur + line[j];
            if(digitsInLetters.count(cur)) {
                return { digitsInLetters[cur], i };
            }
        }
    }

    return {-1, -1};
}

pair<int,int> getLastTextDigit(string line) {
    for(int i = line.size() - 1; i >= 0; i--) {
        string cur = "";
        for(int j = i; j < min(i + 5, (int)line.size()); j++) {
            cur = cur + line[j];
            if(digitsInLetters.count(cur)) {
                return { digitsInLetters[cur], i };
            }
        }
    }

    return {-1, -1};
}

int getNumber(string line) {
    int firstDigitIndex = -1, lastDigitIndex = -1;

    for(int i = 0; i < line.size(); i++) {
        if(line[i] <= '9' and line[i] >= '0') {
            if(firstDigitIndex == -1) {
                firstDigitIndex = i;
            }

            lastDigitIndex = i;
        }
    }

    auto [firstDigit, firstIndex] = getFirstTextDigit(line);
    auto [lastDigit, lastIndex] = getLastTextDigit(line);

    if(firstIndex == -1 or 
        (firstDigitIndex != -1 and firstDigitIndex < firstIndex)) {
            firstDigit = line[firstDigitIndex] - '0';
    }

    if(lastIndex == -1 or
        (lastDigitIndex != -1 and lastDigitIndex > lastIndex)) {
            lastDigit = line[lastDigitIndex] - '0';
    }

    return firstDigit * 10 + lastDigit;
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
    long long total = 0;
    while(getline(cin, line)) {
        int x = getNumber(line);
        total += x;
    }

    cout << total << "\n";

    return 0;
}