/**
 * @file
 * Creating Strings
 * @see https://cses.fi/problemset/task/1622
 */

#include <bits/stdc++.h>

using namespace std;

int f[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    if (s.length() == 0 || s.length() > 8) {
        return 1;
    }

    // input: aabac
    // _           5!
    // P        = -------- = 20
    //  5(3,1,1)   3!1!1!
    map<char, int> uniq = {};
    for (auto c : s) {
        uniq[c]++;
    }
    int l = 1;
    for (auto x : uniq) {
        l *= f[x.second];
    }
    cout << f[s.size()]/l << "\n";

    string origin = s;
    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));

    return 0;
}
