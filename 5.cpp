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

ull to_num(string num) {
    ull x = 0;
    for(char c: num) {
        if(not isDigit(c)) return -1;
        x = x * 10 + (c - '0');
    }
    return x;
}

vector<ull> getNumList(vector<string> v) {
    vector<ull> ans;
    for(string s: v) {
        ans.push_back(to_num(s));
    }

    return ans;
}

vector<string> tokenize(string line, char delimiter) {
    stringstream s(line);
    string token;
    vector<string> tokens;

    while(getline(s, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


vector<ull> parseSeeds(string line) {
    line = line.substr(line.find(":") + 2);
    return getNumList(tokenize(line, ' '));
}

vector<ull> calculate(vector<ull> &seeds, vector<vector<vector<ull>>> &mapList) {
    vector<ull> cur = seeds;
    // debug(cur);
    for(auto cur_map: mapList) {
        sort(cur_map.begin(), cur_map.end());
        // debug(cur_map)

        int start = 0;
        sort(cur.begin(), cur.end());

        for(auto rule: cur_map) {
            ull source_start = rule[0];
            ull destination_start = rule[1];
            ull range = rule[2];

            // debug(rule)

            while(start < cur.size() and cur[start] < source_start + range) {
                if(cur[start] >= source_start) {
                    cur[start] += destination_start - source_start;
                }
                start++;
            }

            // debug(cur)
        }
    }

    return cur;
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
    int first = 1;

    vector<ull> cur;
    vector<vector<vector<ull>>> mapList;

    while(getline(cin, line)) {
        if(first) {
            first = 0;
            cur = parseSeeds(line);
            continue;
        }

        if(line == "") continue;
        if(line.find("map:") != string::npos) {
            // new map added
            vector<vector<ull>> newMap;
            mapList.push_back(newMap);
            continue;
        }
        
        vector<ull> vals = getNumList(tokenize(line, ' '));
        swap(vals[0], vals[1]);
        mapList.back().push_back(vals);
    }

    vector<ull> locationList = calculate(cur, mapList);

    ull lowest = ULLONG_MAX;
    for(ull location: locationList) {
        lowest = min(lowest, location);
    }

    cout << lowest << "\n";

    return 0;
}