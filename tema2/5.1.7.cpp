#include <iostream>

const int NMAX = 10002;
const int VALMAX = 10002;

int v[NMAX];
int w[NMAX];
int st[NMAX];
int fst[VALMAX];
int f[VALMAX];

int main() {
    int n, i, k, x, nn;

    std::cin >> n;

    for (i=0; i<n; i++) {
        std::cin >> v[i];
        f[v[i]]++;
    }

    nn = 0;
    for (i=0; i<n; i++) {
        if (f[v[i]]%2==1) {
            w[nn] = v[i];
            nn++;
        }
    }
    n = nn;
    for (i=0; i<n; i++) {
        v[i] = w[i];
    }

    k = 1;
    st[0] = 0;
    for (i=0; i<n; i++) {
        f[v[i]]--;
        if (fst[v[i]]==0) {
            while (k>0 && v[i]<st[k-1] && f[st[k-1]]>0) {
                fst[st[k-1]] = 0;
                k--;
            }
            st[k] = v[i];
            fst[v[i]] = 1;
            k++;
        }
    }

    for (i=1; i<k; i++) {
        std::cout << st[i] << ' ';
    }

    return 0;
}