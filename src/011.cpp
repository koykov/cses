/**
 * @file
 * Coin Piles
 * @see https://cses.fi/problemset/task/1754
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int mx = max(a, b), mn = min(a, b);
        if (((a+b)%3 == 0 && mx-mn <= mn) || (a == 0 && b == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
