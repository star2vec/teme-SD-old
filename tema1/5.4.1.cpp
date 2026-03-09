#include<iostream>
#include<vector>

int candy[1001];
int n, k;

int check(int x) {
    int nr, i;
    nr = 0;
    for (i=0; i<n; i++) {
         nr+=candy[i]/x;
    }
    if (nr>=k) {
        return 1;
    }
    return 0;
}

int main() {
    int i, st, dr, mijl, maxc;

    std::cin >> n;
    maxc = 0;
    for (i=0; i<n; i++) {
        std::cin >> candy[i];
        if (candy[i]>maxc) {
            maxc = candy[i];
        }
    }
    std::cin>>k;

    st = 0;
    dr = maxc;
    while (dr-st>1) {
        mijl = (st+dr)/2;
        if (check(mijl)==0) {
            dr = mijl;
        } else {
            st = mijl;
        }
    }

    std::cout << st;

    return 0;
}