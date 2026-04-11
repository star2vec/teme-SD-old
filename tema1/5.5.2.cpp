#include <iostream>

using namespace std;

#define MOD 16536
#define NMAX 100005

int key[NMAX];
int val[NMAX];

int st[NMAX];
int dr[NMAX];

int h[MOD];
int nexth[NMAX];

int nmax;
int n;

void kicklru(int id) {
    dr[st[id]] = dr[id];
    st[dr[id]] = st[id];
}

void switchfront(int id) {
    dr[id] = dr[0];
    st[id] = 0;
    st[dr[0]] = id;
    dr[0] = id;
}

void kickhash(int hashval, int id) {
    int p;

    if (h[hashval] == id) {
        h[hashval] = nexth[id];
        return;
    }

    p = h[hashval];
    while (p!=0 && nexth[p]!=0) {
        if (nexth[p] == id) {
            nexth[p] = nexth[id];
            return;
        }
        p = nexth[p];
    }
}

void bagahash(int hashval, int id) {
    nexth[id] = h[hashval];
    h[hashval] = id;
}

void init(int k) {
    int i;

    nmax = k;
    n = 0;
    dr[0] = 0;
    st[0] = 0;
    for (i=0; i<MOD; i++) {
        h[i] = 0;
    }
}

int get(int x) {
    int hashval;
    int p;

    hashval = (x%MOD+MOD)%MOD;
    p = h[hashval];
    while (p != 0) {
        if (key[p] == x) {
            kicklru(p);
            switchfront(p);
            return val[p];
        }
        p = nexth[p];
    }
    return -1;
}

void put(int x, int y) {
    int hashval, p, newid, oldhashval;

    hashval = (x%MOD+MOD)%MOD;
    p = h[hashval];
    while (p != 0) {
        if (key[p] == x) {
            val[p] = y;
            kicklru(p);
            switchfront(p);
            return;
        }
        p = nexth[p];
    }

    if (n == nmax) {
        newid = st[0];
        kicklru(newid);
        oldhashval = (key[newid]%MOD+MOD)%MOD;
        kickhash(oldhashval, newid);
    } else {
        n++;
        newid = n;
    }

    key[newid] = x;
    val[newid] = y;
    switchfront(newid);
    bagahash(hashval, newid);
}

int main() {

    return 0;
}