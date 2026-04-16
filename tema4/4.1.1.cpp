#include <iostream>

#define NMAX 1002

int bst[NMAX];
int st[NMAX];
int dr[NMAX];
int dad[NMAX];
int treesize;
int root;

int v[NMAX];
int n;

int exists(int val) {
    int idx;
    idx = root;
    while (idx != -1) {
        if (bst[idx] == val) {
            return 1;
        }
        if (val < bst[idx]) {
            idx = st[idx];
        } else {
            idx = dr[idx];
        }
    }
    return 0;
}

int predecessor(int val) {
    int idx, pred;
    idx = root;
    while (idx != -1) {
        if (val < bst[idx]) {
            pred = bst[idx];
            idx = st[idx];
        } else {
            idx = dr[idx];
        }
    }
    return pred;
}

int successor(int val) {
    int idx, succ;
    idx = root;
    while (idx != -1) {
        if (val < bst[idx]) {
            succ = bst[idx];
            idx = st[idx];
        } else {
            idx = dr[idx];
        }
    }
    return succ;
}

void nodnou(int val, int parent) {
    bst[treesize] = val;
    st[treesize] = -1;
    dr[treesize] = -1;
    dad[treesize] = parent;
    treesize++;
}

void insert(int val) {
    int idx, ok;

    if (root == -1) {
        nodnou(val, -1);
        root = treesize-1;
        return;
    }

    idx = root;
    ok = 0;
    while (ok == 0) {
        if (val < bst[idx]) {
            if (st[idx] == -1) {
                nodnou(val, idx);
                st[idx] = treesize-1;
                ok = 1;
            }
            idx = st[idx];
        } else if (val > bst[idx]) {
            if (dr[idx] == -1) {
                nodnou(val, idx);
                dr[idx] = treesize-1;
                ok = 1;
            }
            idx = dr[idx];
        } else {
            ok = 1;
        }
    }
}

void construct() {
    int i;

    root = -1;
    for (i=0; i<n; i++) {
        insert(v[i]);
    }
}

void erase(int val) {
    int idx, succ, pred, child;

    idx = root;

    idx = root;
    while (idx!=-1 && val!=bst[idx]) {
        if (val < bst[idx]) {
            idx = st[idx];
        } else {
            idx = dr[idx];
        }
    }

    if (st[idx]!=-1 && dr[idx]!=-1) {
        succ = dr[idx];
        while (st[succ] != -1) {
            succ = st[succ];
        }
        bst[idx] = bst[succ];
        idx = succ;
    }

    if (st[idx] != -1) {
        child = st[idx];
    } else {
        child = dr[idx];
    }

    if (child != -1) {
        dad[child] = dad[idx];
    }

    if (dad[idx] == -1) {
        root = child;
    } else if (idx == st[dad[idx]]) {
        st[dad[idx]] = child;
    } else {
        dr[dad[idx]] = child;
    }
}

int main() {
    return 0;
}