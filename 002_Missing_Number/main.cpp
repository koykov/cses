#include <iostream>
#include <fstream>

const int MAX_N = 200000;

int main() {
    int a[MAX_N+1] = {0};
    int n, i, x;

    std::cin >> n;
    if (n < 1 || n > MAX_N) {
        return 1;
    }
    for (i=0; i<n-1; i++) {
        std::cin >> x;
        a[x] = x;
    }
    for (i=1; i<=n; i++) {
        if (a[i] == 0) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
