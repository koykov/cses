/**
 * @file
 * Two Sets
 * @see https://cses.fi/problemset/task/1092
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

    long ap = (1+n)*n/2; // sum of [1-n] is an arithmetic progression (diff 1)
    if (ap%2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    
    long target = ap/2;
    if (n == target) {
        cout << 1 << "\n" << n << "\n";
        cout << n-1 << "\n";
        for (int i=1; i<n; i++) {
            cout << i << " ";
        }
        return 0;
    }

    bool f[MAX_N+1] = {false};
    int m[MAX_N/2] = {0};
    int l = 0, i = 0;
    long s = 0;
    
    for (i=n; i>0; i--) {
        if (s+i <= target) {
            f[i] = true;
            m[l] = i;
            l++;
            s += i;
            if (s == target) {
                break;
            }
        }
    }
    cout << l << "\n";
    for (i=0; i<l; i++) {
        cout << m[i] << " ";
    }
    cout << "\n";

    cout << n-l << "\n";
    for (i=1; i<n; i++) {
        if (!f[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
