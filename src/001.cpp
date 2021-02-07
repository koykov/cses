/**
 * @file
 * Weird Algorithm
 * @see https://cses.fi/problemset/task/1068
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long n = 0;
    cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }
    cout << n << " ";
    while (n > 1) {
        if (n%2 == 0) {
            n = n / 2;
        } else {
            n = n*3+1;
        }
        cout << n << " ";
    }
    return 0;
}
