/**
 * @file
 * Missing Number
 * @see https://cses.fi/problemset/task/1083
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)2e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[MAX_N+1] = {0};
    int n = 0, i = 0, x = 0;

    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }
    for (i=0; i<n-1; i++) {
        cin >> x;
        a[x] = x;
    }
    for (i=1; i<=n; i++) {
        if (a[i] == 0) {
            cout << i;
            break;
        }
    }
    return 0;
}
