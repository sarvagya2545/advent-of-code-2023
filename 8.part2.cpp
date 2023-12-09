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

ull getStepsTillFirstZ(string input, map<string,string> &left, map<string,string> &right, string &instructions) {
    int n = instructions.size();
    ull steps = 0;
    int i = 0;
    int maxSteps = 1e6;
    string node = input;

    while(node[2] != 'Z') {
        steps++;
        if(instructions[i] == 'L') {
            node = left[node];
        } else {
            node = right[node];
        }

        i++;
        if(i == n) i = 0;

        if(steps > maxSteps) {
            cerr << "STEPS EXCEEDED: ";
            debug(input)
            break;
        }
    }

    return steps;
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

    string instructions;
    cin >> instructions;

    string line;

    map<string, string> left, right;
    vector<string> startNodes;

    while(getline(cin, line)) {
        if(line == "") continue;

        string currentNode = line.substr(0, 3);
        string leftNode = line.substr(7, 3);
        string rightNode = line.substr(12, 3);

        left[currentNode] = leftNode;
        right[currentNode] = rightNode;

        if(currentNode[2] == 'A') startNodes.push_back(currentNode);
    }

    /*
    
    Note: in general case it is not correct to do this, however, the input for Advent of code is made in such a way that the number of steps from a starting node to the first target node is the same as the number of steps needed to cycle back to the target node.
    
    */


    ull ans = 1;
    for(auto node: startNodes) {
        ull steps = getStepsTillFirstZ(node, left, right, instructions);
        ans = lcm(ans, steps);
    }

    cout << ans << "\n";

    return 0;
}