#include <iostream>

const int NMAX = 1001;
int v[NMAX];

int main() {
    int n, i, turtle, bunny;

    std::cin >> n;
    for (i=0; i<=n; i++) {
        std::cin >> v[i];
    }

    turtle = bunny = 0;
    do {
        turtle = v[turtle];
        bunny = v[v[bunny]];
    } while (turtle != bunny);

    turtle = 0;
    do {
        turtle = v[turtle];
        bunny = v[bunny];
    } while (turtle != bunny);

    std::cout << bunny;

    return 0;
}