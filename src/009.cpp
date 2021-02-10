/**
 * @file
 * Bit Strings
 * @see https://cses.fi/problemset/task/1617
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e6;
const long long MODULO = (long long)1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }

    long long x = 2;
    for (long long i=1; i<n; i++) {
        x = (x*2)%MODULO;
    }
    
    cout << x;

    return 0;
}
