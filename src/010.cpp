/**
 * @file
 * Trailing Zeros
 * @see https://cses.fi/problemset/task/1618
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    long p = 5;
    int f = n, c = 0;
    while (f > 1) {
        f = n/p;
        c += n/p;
        p *= 5;
    }

    cout << c;

    return 0;
}
