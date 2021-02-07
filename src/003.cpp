/**
 * @file
 * Repetitions
 * @see https://cses.fi/problemset/task/1069
 */

#include <bits/stdc++.h>

using namespace std;

int get_idx(char c) {
    int r;
    switch (c) {
        case 'A':
            r = 0;
            break;
        case 'C':
            r = 1;
            break;
        case 'G':
            r = 2;
            break;
        case 'T':
            r = 3;
            break;
        default:
            r = -1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int sl[4] = {0};

    cin >> s;

    char c = '\0';
    int x = 0, y = 0;
    for (auto b : s) {
        if (b != c) {
            int l = y-x;
            int i = get_idx(c);
            if (i < 0) {
                c = b;
                y++;
                continue;
            }
            if (l > sl[i]) {
                sl[i] = l;
            }
            c = b;
            x = y;
        }
        y++;
    }

    int l = y-x;
    int i = get_idx(c);
    if (l > sl[i]) {
        sl[i] = l;
    }

    cout << *max_element(sl, sl+4);

    return 0;
}
