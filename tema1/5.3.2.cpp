#include <iostream>

const int NMAX = 1001;
int next[NMAX];

int main() {
    int n, i, turtle, bunny, lung;

    std::cin >> n;
    for (i=0; i<=n; i++) {
        std::cin >> next[i];
    }

    turtle = bunny = 0;
    do {
        turtle = next[turtle];
        if (next[bunny]!=-1) {
            bunny = next[next[bunny]];
        }
    } while (turtle != bunny && bunny != -1 && next[bunny] != -1);

    if (bunny == -1 || next[bunny] == -1) {
            std::cout << "fara ciclu :P";
    } else {
        turtle = 0;
        while (turtle != bunny) {
            turtle = next[turtle];
            bunny = next[bunny];
        }
        std::cout << "inceputul ciclului: " << bunny << '\n';

        lung = 1;
        bunny = next[bunny];
        while (turtle != bunny) {
            bunny = next[bunny];
            lung++;
        }
        std::cout << "lungime ciclu: " << lung << '\n';
    }

    return 0;
}
