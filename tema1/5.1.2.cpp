#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NMAX 100001
#define MAX 10000001

int v[NMAX];

int main() {
    int n, s, i, st, dr, valmin, mini, minj, val;

    scanf("%d%d", &n, &s);

    for (i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    valmin = MAX;
    st = 0;
    dr = n-1;
    while (st<dr) {
        do {
            val = abs(v[st]+v[dr]-s);
            if (val<valmin) {
                valmin = val;
                mini = st;
                minj = dr;
            }
            dr--;
        } while (v[st]+v[dr]>=s && st<dr);
        dr++;
        st++;
    }

    printf("%d %d\n", mini, minj);

    return 0;
}