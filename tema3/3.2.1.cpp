#include <iostream>

#define NMAX 1002
#define VALMAX 2002 ///de 2 ori maximul valorii max din vector

int a[NMAX];
int hash[VALMAX];
 
int main() {
    int n, i, j, k, s, ok;
    
    std::cin >> n >> s;

    for (i=0; i<n; i++) {
        std::cin >> a[i];
    }

    for (i=0; i<n-2; i++) {
        for (j=i+1; j<n-1; j++) {
            hash[a[i]+a[j]] = j*NMAX + i;
        }
    }

    ok = 0;
    for (k=2; k<n && ok==0; k++) {
        if (hash[s-a[k]]!=0) {
            i = hash[s-a[k]]%NMAX;
            j = hash[s-a[k]]/NMAX;
            if (j<k) {
                ok = 1;
            }
        }
    }
    k--;

    if (ok==0) {
        std::cout << "nu exista :C";
    } else {
        std::cout << i << ' ' << j << ' ' << k << '\n';
    }

    return 0;
}
