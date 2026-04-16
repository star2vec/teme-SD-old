#include <iostream>
#include <stdio.h>

#define NMAX 1002

int bst[NMAX];
int st[NMAX];
int dr[NMAX];
int dad[NMAX];
int treesize;
int root;

int s[NMAX];
int ns;
int sidx;

void serialize(int idx) {
    if (idx == -1) {
        return;
    }
    s[ns] = bst[idx];
    ns++;
    serialize(st[idx]);
    serialize(dr[idx]);
}

int deserialize(int mini, int maxi) {
    int val, idx;

    if (sidx == ns) {
        return -1;
    }

    val = s[sidx];
    if (val<=mini || val>=maxi) {
        return -1;
    }

    idx = treesize;
    treesize++;
    bst[idx] = val;
    sidx++;

    st[idx] = deserialize(mini, val);
    dr[idx] = deserialize(val, maxi);

    return idx;
}

#define INF 1000000001

int main() {
    int idk;

    ns = 0;
    serialize(root);

    treesize = 0;
    sidx = 0;
    idk = deserialize(0, INF);

    return 0;
}