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

template<class T>
vector<T> filter(vector<T> v, T garbage) {
    vector<T> ans;
    for(auto i: v) {
        if(i == garbage) continue;
        ans.push_back(i);
    }

    return ans;
}

template<class T, class U>
vector<T> convert(vector<U> v, function<T(U)> transform) {
    vector<T> ans;

    for(U item: v) {
        ans.push_back(transform(item));
    }

    return ans;
}

string joinAll(vector<string> v) {
    string all = "";
    for(string s: v) {
        all += s;
    }

    return all;
}

bool isDigit(char c) {
    return c <= '9' and c >= '0';
}

ull to_num(string num) {
    ull x = 0;
    for(char c: num) {
        if(not isDigit(c)) return -1;
        x = x * 10 + (c - '0');
    }
    return x;
}

vector<ull> parsePart1(string s) {
    return convert<ull, string>(filter<string>(tokenize(s, ' '), ""), to_num);
}

ull parsePart2(string s) {
    return to_num(joinAll(tokenize(s, ' ')));
}

ull solvePart1(vector<ull> times, vector<ull> distances) {
    ull ans = 1;
    for(int raceIdx = 0; raceIdx < times.size(); raceIdx++) {
        ull time = times[raceIdx], record_dist = distances[raceIdx];

        int cnt = 0;
        for(int charge = 0; charge <= time; charge++) {
            int travelled = (time - charge) * charge;
            if(travelled > record_dist) {
                cnt++;
            }
        }

        ans *= cnt;
    }

    return ans;
}

ull solvePart2(ull time, ull recordDistance) {
    ull maxima = time / 2ULL;

    ull left = 0, right = maxima - 1, ans1 = maxima, ans2 = maxima - 1;
    while(left <= right) {
        ull mid = left + (right - left) / 2ULL;

        bool beatsTheRecord = mid * (time - mid) > recordDistance;
        if(beatsTheRecord) {
            ans1 = mid;
            right = mid - 1ULL;
        } else {
            left = mid + 1ULL;
        }
    }

    left = maxima, right = time;
    while(left <= right) {
        ull mid = left + (right - left) / 2ULL;

        bool beatsTheRecord = mid * (time - mid) > recordDistance;
        if(beatsTheRecord) {
            ans2 = mid;
            left = mid + 1ULL;
        } else {
            right = mid - 1ULL;
        }
    }

    return max(ans2 - ans1 + 1ULL, 0ULL);
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

    string timeString, distanceString;
    getline(cin, timeString);
    getline(cin, distanceString);

    timeString = timeString.substr(11);
    distanceString = distanceString.substr(11);

    cout << solvePart1(parsePart1(timeString), parsePart1(distanceString)) << "\n";
    cout << solvePart2(parsePart2(timeString), parsePart2(distanceString)) << "\n";

    return 0;
}