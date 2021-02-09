/**
 * @file
 * Two Knights
 * @see https://cses.fi/problemset/task/1072
 */

#include <bits/stdc++.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

using namespace std;

const int MAX_N = (int)1e4;
const int m[4] = {0, 6, 28, 96};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    for (int k=1; k<=n; k++) {
        long r = 0;
        if (unlikely(k<5)) {
            r = m[k-1];
        } else {
            long k2 = k*k;
            int k4 = k-4;
            r = 4*(k2-3);        // knight in the corners
            r += 4*(k2-5);       // knight in the inner corners
            r += 8*(k2-4);       // knight around the corners
            r += 4*(k4)*(k2-5);  // knight on the edges
            r += 4*(k4)*(k2-7);  // knight on the inner edges
            r += k4*k4*(k2-9);   // knight inside the chessboard (excluding all upper cases)
            r /= 2;
        }

        cout << r << "\n";
    }

    return 0;
}
