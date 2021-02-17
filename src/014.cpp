/**
 * @file
 * Tower of Hanoi
 * @see https://cses.fi/problemset/task/2165
 */

#include <bits/stdc++.h>

using namespace std;

void toh_recursive(int n, int f, int t, int b) {
    if (n == 0) {
        return;
    }
    toh_recursive(n-1, f, b, t);
    cout << f << " " << t << "\n";
    toh_recursive(n-1, b, t, f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    cin >> n;
    if (n < 1 || n > 16) {
        return 1;
    }

    cout << (1u << n) - 1 << "\n";
    toh_recursive(n, 1, 3, 2);

    return 0;
}
