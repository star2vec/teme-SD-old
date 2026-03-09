#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NMAX 101

int a[NMAX];
int sum[NMAX];

int main() {
    int n, q, qq, l, r, i, k;

    scanf("%d%d", &n, &q);

    for (i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    
    sum[1] = a[1];
    for (i=2; i<=n; i++) {
        sum[i] = sum[i-1] + a[i];
    }

    for (qq=0; qq<q; qq++) {
        scanf("%d%d", &l, &r);
        printf("%d", sum[r]-sum[l-1]);
    }

    return 0;
}