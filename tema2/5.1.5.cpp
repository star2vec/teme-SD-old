#include <iostream>

const int NMAX = 10002;

int st[NMAX];
int val[NMAX];
int v[NMAX];

int main() {
    int n, i, kst, lung, k, j;

    std::cin >> n >> k;

    for (i=1; i<=n; i++) {
        std::cin >> v[i];
    }

    v[0] = -1;
    kst = 1;
    lung = 0;
    for (i=1; i<=n; i++) {
        if (v[i]!=v[i-1] && i>1) {
            if (val[kst-1]==v[i-1]) {
                st[kst-1] += lung;
            } else {
                val[kst] = v[i-1];
                st[kst] = lung;
                kst++;
            }

            st[kst-1] = st[kst-1]%k;

            if (st[kst-1] == 0) {
                kst--;
            }

            lung = 1;

        } else {
            lung++;
        }
    }

    if (kst > 0 && val[kst-1] == v[n]) {
        st[kst-1] += lung;
    } else {
        val[kst] = v[n];
        st[kst] = lung;
        kst++;
    }
    st[kst-1] = st[kst-1] % k;
    if (st[kst-1] == 0) {
        kst--;
    }


    for (i=0; i<kst; i++) {
        for (j=0; j<st[i]; j++) {
            std::cout << val[i] << ' ';
        }
    }

    return 0;
}