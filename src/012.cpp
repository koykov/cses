/**
 * @file
 * Palindrome Reorder
 * @see https://cses.fi/problemset/task/1755
 */

#include <bits/stdc++.h>
#include <map>

using namespace std;

const int MAX_L = (int)1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    if (s.length() == 0 || s.length() > MAX_L) {
        return 1;
    }

    map<char, int> h = {};
    for (auto c : s) {
        h[c]++;
    }

    int oc = 0, r = 0;
    char o = '\0';
    for (auto x : h) {
        if (x.second%2 > 0) {
            oc++;
            o = x.first;
            r = x.second;
        }
    }

    if (oc > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    string l;
    for (auto x : h) {
        if (x.first == o) {
            continue;
        }
        l += string(x.second/2, x.first);
    }

    cout << l;
    if (oc == 1) {
        cout << string(r, o);
    }
    for (int i=l.length()-1; i>=0; i--) {
        cout << l[i];
    }

    return 0;
}
