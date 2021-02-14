/**
 * @file
 * Gray Code
 * @see https://cses.fi/problemset/task/2205
 * @see https://en.wikipedia.org/wiki/Hamming_distance
 * @see https://en.wikipedia.org/wiki/Gray_code
 */

#include <bits/stdc++.h>

using namespace std;

void g(unsigned int n, unsigned int* m, unsigned int depth) {
    int i, t = (1u << (depth - 1));

    if (depth == 0) {
        m[0] = 0;
    } else {
        for (i = 0; i < t; i++) {
            m[t + i] = m[t - i - 1] + (1u << (depth - 1));
        }
    }
    if (depth != n) {
        g(n, m, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    cin >> n;
    if (n < 1 || n > 16) {
        return 1;
    }
    
    unsigned int m[1u<<16u] = {0};
    g(n, m, 0);

    for (int i=0; i<(1u<<n); i++) {
        string b = bitset<16>(m[i]).to_string();
        cout << b.substr(16-n, n) << "\n";
    }

    return 0;
}
