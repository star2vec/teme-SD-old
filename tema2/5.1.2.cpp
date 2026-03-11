#include <iostream>

const int NMAX = 10002;

int st[NMAX];
int v[NMAX];

int left[NMAX];
int right[NMAX];

int main() {
    int n, i, k, area, amax, idxmax;

    std::cin >> n;
    v[0] = 0;
    st[0] = 0;
    k = 1;
    for (i=1; i<=n; i++) {
        std::cin >> v[i];
        while (k>0 && v[i]<v[st[k-1]]) {
            k--;
        }
        left[i] = st[k-1];
        st[k] = i;
        k++;
    }


    v[n] = 0;
    st[0] = n+1;
    k = 1;
    for (i=n; i>=1; i--) {
        while (k>0 && v[i]<v[st[k-1]]) {
            k--;
        }
        right[i] = st[k-1];
        st[k] = i;
        k++;
    }

    amax = 0;
    idxmax = 0;
    for (i=1; i<=n; i++) {
        area = v[i]*(right[i]-left[i]-1);
        if (amax < area) {
            amax = area;
            idxmax = i;
        }
    }

    std::cout << amax << '\n';

    return 0;
}