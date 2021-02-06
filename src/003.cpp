#include <iostream>
#include <algorithm>

int main() {
    std::string s;
    int sl[4] = {0};

    std::cin >> s;

    char c = '\0';
    int x = 0, y = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] != c) {
            int l = y-x;
            int a = -1;
            switch (c) {
                case 'A':
                    a = 0;
                    break;

                case 'C':
                    a = 1;
                    break;

                case 'G':
                    a = 2;
                    break;

                case 'T':
                    a = 3;
                    break;
            }
            if (a < 0) {
                c = s[i];
                y++;
                continue;
            }
            if (l > sl[a]) {
                sl[a] = l;
            }
            c = s[i];
            x = y;
        }
        y++;
    }

    int l = y-x;
    int a = -1;
    switch (c) {
        case 'A':
            a = 0;
            break;

        case 'C':
            a = 1;
            break;

        case 'G':
            a = 2;
            break;

        case 'T':
            a = 3;
            break;
    }
    if (l > sl[a]) {
        sl[a] = l;
    }

    std::cout << *std::max_element(sl, sl+4);

    return 0;
}
