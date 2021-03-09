/**
 * @file
 * Chessboard and Queens
 * @see https://cses.fi/problemset/task/1624
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int buf[N] = {-1, -1, -1, -1, -1, -1, -1, -1};
bool in[N][N];
int out = 0;

bool chk(int a, int b)
{
    if (in[a][b]) return false;
    for (int i = 0; i < N; i++) {
        if (buf[i] == b) return false;
        if (i > 0 && i <= a && b-i >= 0 && buf[a-i] == b-i) return false;
        if (i > 0 && i <= a && b+i < N && buf[a-i] == b+i) return false;
    }

    return true;
}

void f(int a) {
    if(a == N) {
        out++;
        return;
    }

    for (int i=0; i<N; ++i) {
        if(chk(a, i)) {
            buf[a] = i;
            f(a+1);
            buf[a] = -1;
        }
    }
}

int main() {
    char c;
    for (auto & i : in) {
        for (bool & j : i) {
            cin >> c;
            j = c == '*';
        }
    }

    f(0);
    cout << out;

    return 0;
}
