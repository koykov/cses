/**
 * @file
 * Number Spiral
 * @see https://cses.fi/problemset/task/1071
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_T = (int)1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    if (t < 1 || t > MAX_T) {
        return 1;
    }

    for (int i=0; i<t; i++) {
        long y = 0, x = 0;
        cin >> y >> x;
        long n = max(y, x);
        long d = n - min(y, x);
        long long dv = n*n - n+1;
        if (d == 0) {
            cout << dv << "\n";
            continue;
        }
        if (n%2 == 0) {
            cout << dv + (x>y ? -d : d) << "\n";
        } else {
            cout << dv + (x>y ? d : -d) << "\n";
        }
    }

    return 0;
}
