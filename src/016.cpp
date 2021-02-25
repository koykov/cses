/**
 * @file
 * Apple Division
 * @see https://cses.fi/problemset/task/1623
 */

#include <bits/stdc++.h>

typedef unsigned int uint;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint n;
    cin >> n;
    if (n < 1 || n > 20) {
        return 1;
    }

    int p[20] = {0};
    long w = 0;
    for (int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        p[i] = x;
        w += x;
    }

    long mx = 0;
    long w2 = w/2 + w%2;
    for (uint m=0; m<((uint)1<<n); ++m) {
        long s = 0;
        for (uint i=0; i<n; i++) {
            if (m & ((uint)1<<i)) {
                if (s + p[i] > w2) {
                    break;
                } 
                s += p[i];
            }
            if (s == w2) {
                cout << abs(2*w2 - w);
                return 0;
            }
        }
        mx = mx < s ? s : mx;
    }

    cout << abs(2*mx - w);

    return 0;
}
