#include <iostream>

#define NMAX 1002

int bst[NMAX];
int st[NMAX];
int dr[NMAX];
int dad[NMAX];
int treesize;
int root;

int valid(int idx, int mini, int maxi) {
    int okst, okdr;

    if (idx==-1) {
        return 1;
    }

    if (bst[idx]<=mini || bst[idx]>=maxi) {
        return 0;
    }

    okst = valid(st[idx], mini, bst[idx]);
    okdr = valid(dr[idx], bst[idx], maxi);

    return okst*okdr;
}

#define INF 1000000001

int main() {
    valid(root, 0, INF);
    return 0;
}