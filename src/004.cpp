/**
 * @file
 * Increasing Array
 * @see https://cses.fi/problemset/task/1094
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    long x = 0, p = 0, r = 0;

    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    for (int i=0; i<n; i++) {
        cin >> x;
        if (x < p) {
            r += p-x;
            x = p;
        }
        p = x;
    }

    cout << r;

    return 0;
}
