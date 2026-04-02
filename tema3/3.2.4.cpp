#include <iostream>

#define NMAX 1002
#define VALMAX 1002

int a[NMAX];
int f[VALMAX];
int n;

int count(int k) {
    int i, nrd, st, dr, nrsecv;

    for (i=0; i<VALMAX; i++) {
        f[i] = 0;
    }

    nrsecv = 0;
    nrd = 0;
    st = 0;
    dr = 0;
    for (i=0; i<n; i++) {
        if (f[a[i]]==0) {
            nrd++;
        }
        f[a[i]]++;
        if (nrd>k) {
            while (nrd>k) {
                f[a[st]]--;
                if (f[a[st]]==0) {
                    nrd--;
                }
                st++;
            }
        }
        nrsecv += (i-st+1);
    }

    return nrsecv;
}


int main() {
    int i, l, r, rez;

    std::cin >> n >> l >> r;

    for (i=0; i<n; i++) {
        std::cin >> a[i];
    }

    rez = count(r) - count(l-1);

    std::cout << rez << '\n';

    return 0;
}
