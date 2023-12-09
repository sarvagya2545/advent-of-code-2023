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
template<class T, class U> void __print(pair<T, U> x) {cerr << "{ "; __print(x.ff); cerr << ", "; __print(x.ss); cerr << " }";}
template<class T> void __print(vector<T> x) {cerr << "[ "; for(T i: x) {__print(i); cerr << " "; } cerr << " ]";}
template<class T> void __print(set<T> x) {cerr << "[ "; for(T i: x) { __print(i); cerr << " "; } cerr << "]";}
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

enum handType { 
    high_card, 
    one_pair, 
    two_pair, 
    three_of_kind, 
    full_house, 
    four_of_kind, 
    five_of_kind
};

handType getHandType(string cards) {
    assert(cards.length() == 5);

    string newStr = "";
    int j = 0;
    for(char c: cards) {
        if(c == 'J') j++;
        else newStr += c;
    }

    map<char,int> s;
    int maxFreq = 0;
    for(char c: newStr) {
        if(not s.count(c))
            s.insert({ c, 0 });
        s[c]++;

        maxFreq = max(maxFreq, s[c]);
    }

    maxFreq += j;

    if(s.size() <= 1) return five_of_kind;

    if(s.size() == 2) {
        if(maxFreq == 4) return four_of_kind;
        else return full_house;
    }

    if(s.size() == 3) {
        if(maxFreq == 3) return three_of_kind;
        else return two_pair;
    }

    if(s.size() == 5) return high_card;

    return one_pair;
}

int getCardValue(char c) {
    map<char,int> mp = {
        {'J', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'T', 10},
        {'Q', 11},
        {'K', 12},
        {'A', 13},
    };

    return mp[c];
}

// return true if hand2 is stronger than hand1 else false
bool compareHand(pair<string,int> &hand1, pair<string,int> &hand2) {
    handType handType1 = getHandType(hand1.first), handType2 = getHandType(hand2.first);

    if(handType2 == handType1) {
        for(int i = 0; i < 5; i++) {
            if(hand2.first[i] == hand1.first[i]) continue;
            
            int cardValue1 = getCardValue(hand1.first[i]);
            int cardValue2 = getCardValue(hand2.first[i]);
            return cardValue2 > cardValue1;
        }
    }

    return handType2 > handType1;
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
    vector<pair<string,int>> hands;

    while(getline(cin, line)) {
        string cards = line.substr(0, 5);
        int bid = (int)to_num(line.substr(6));
        hands.push_back({ cards, bid });
    }

    sort(hands.begin(), hands.end(), compareHand);
    debug(hands);

    long long totalWinnings = 0;
    for(int i = 0; i < hands.size(); i++) {
        totalWinnings += (long long)hands[i].second * (i + 1);
    }

    debug(getHandType("JJJJJ"))

    cout << totalWinnings;

    return 0;
}