/**
 * @file
 * Weird Algorithm
 * @see https://cses.fi/problemset/task/1068
 */

#include <iostream>

int main() {
    long n = 0;
    std::cin >> n;
    if (n < 1 || n > 1e6) {
        return 1;
    }
    std::cout << n << " ";
    while (n > 1) {
        if (n%2 == 0) {
            n = n / 2;
        } else {
            n = n*3+1;
        }
        std::cout << n << " ";
    }
    return 0;
}
