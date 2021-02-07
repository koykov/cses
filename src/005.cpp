/**
 * @file
 * Permutations
 * @see https://cses.fi/problemset/task/1070
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    if (n == 1) {
        cout << 1;
        return 0;
    }
    
    if (n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i=2; i<=n; i+=2) {
        cout << i << " ";
    }
    for (int i=1; i<=n; i+=2) {
        cout << i << " ";
    }

    return 0;
}
