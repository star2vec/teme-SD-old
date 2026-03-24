#include <iostream>

const int NMAX = 10002;

int st[NMAX];

int k[NMAX][NMAX];

int knows(int i, int j) {
    return k[i][j];
}

int main() {
    int n, i, j, a, b;

    std::cin >> n;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            std::cin >> k[i][j];
        }
    }

    for (i=0; i<n; i++) {
        st[i] = i;
    }

    for (i=n-1; i>=1; i--) {
        a = st[i];
        b = st[i-1];
        if (knows(a, b) == 0) {
            st[i-1] = a;
        } else {
            st[i-1] = b;
        }
    }

    std::cout << st[0];

    return 0;
}