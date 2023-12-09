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


vector<vector<ull>> parseSeeds(string line) {
    line = line.substr(line.find(":") + 2);
    vector<ull> list = getNumList(tokenize(line, ' '));
    vector<vector<ull>> seedIntervals;

    for(int i = 0; i < list.size(); i += 2) {
        ull st = list[i];
        ull len = list[i + 1];
        ull en = st + len - 1;
        seedIntervals.push_back({ st, en });
    }

    return seedIntervals;
}

void merge(vector<vector<ull>> &nextIntervals) {
    vector<vector<ull>> mergedIntervals;
    for(int i = 0; i < nextIntervals.size(); i++) {
        if(mergedIntervals.empty()) {
            mergedIntervals.push_back(nextIntervals[i]);
            continue;
        }

        ull l1 = mergedIntervals.back()[0], r1 = mergedIntervals.back()[1];
        ull l2 = nextIntervals[i][0], r2 = nextIntervals[i][1];
        if(max(l1, l2) > min(r1, r2)) {
            mergedIntervals.push_back(nextIntervals[i]);
        } else {
            mergedIntervals.back() = {
                min(l1, l2),
                max(r1, r2)
            };
        }
    }

    nextIntervals = mergedIntervals;
}

ull calculate(vector<vector<ull>> currIntervals, vector<vector<vector<ull>>> &mapList) {

    vector<vector<ull>> nextIntervals;

    for(auto cur_map: mapList) {
        sort(currIntervals.begin(), currIntervals.end());
        sort(cur_map.begin(), cur_map.end());

        int ruleIdx = 0;
        
        for(auto interval: currIntervals) {
            ull interval_start = interval[0], interval_end = interval[1];

            while(ruleIdx < cur_map.size()) {
                ull source_start = cur_map[ruleIdx][0];
                ull destination_start = cur_map[ruleIdx][1];
                ull range = cur_map[ruleIdx][2];

                ull source_end = source_start + range - 1;
                ull destination_end = destination_start + range - 1;

                if(source_end < interval_start) {
                    ruleIdx++;
                    continue;
                }

                if(source_start > interval_end) {
                    break;
                }

                if(interval_start < source_start) {
                    nextIntervals.push_back({ interval_start, source_start - 1ULL });
                    interval_start = source_start;
                }

                // now interval_start >= source_start

                if(source_end >= interval_end) {
                    // interval is getting skipped after this
                    interval_start += destination_start - source_start;
                    interval_end += destination_start - source_start;
                    break;
                } else {
                    // change the intersection and move on to the next interval
                    nextIntervals.push_back({
                        interval_start + destination_start - source_start,
                        source_end + destination_start - source_start
                    });

                    interval_start = source_end + 1;
                    ruleIdx++;
                }
            }

            if(interval_end >= interval_start)
                nextIntervals.push_back({ interval_start, interval_end });
        }

        sort(nextIntervals.begin(), nextIntervals.end());
        merge(nextIntervals);
        currIntervals = nextIntervals;
        nextIntervals.clear();
    }

    return currIntervals[0][0];
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

    vector<vector<ull>> currIntervals;
    vector<vector<vector<ull>>> mapList;

    while(getline(cin, line)) {
        if(first) {
            first = 0;
            currIntervals = parseSeeds(line);
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

    cout << calculate(currIntervals, mapList);

    return 0;
}