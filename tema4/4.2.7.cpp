#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 100001

int n;
int high[NMAX];
int low[NMAX];

int check(int k) {
    int jos, sus, idx, i;

    idx = 1;
    for (i=0; i<n && idx<=k; i++) {
        jos = max(1, k-high[i]);
        sus = low[i]+1;

        if (jos<=idx && idx<=sus) {
            idx++;
        }
    }

    if (idx<=k) {
        return 0;
    }
    return 1;
}


int main() {
    int st, dr, i, mijl;

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> low[i] >> high[i];
    }

    st = 0;
    dr = n+1;
    while (dr-st>1) {
        mijl = (dr+st)/2;
        if (check(mijl)==0) {
            dr = mijl;
        } else {
            st = mijl;
        }
    }
    cout << st << '\n';

    return 0;
}