#include <iostream>

using namespace std;

#define MOD 16536
#define NMAX 100001

int key[NMAX];
int val[NMAX];
int f[NMAX];

int st[NMAX];
int dr[NMAX];
int prim[NMAX];
int ultim[NMAX];

int h[MOD];
int nexth[NMAX];

int nmax;
int n;
int frmin;

void kicklru(int id) {
    int frecv;

    frecv = f[id];
    if (st[id] != 0) {
        dr[st[id]] = dr[id];
    } else {
        prim[frecv] = dr[id];
    }
    if (dr[id] != 0) {
        st[dr[id]] = st[id];
    } else {
        ultim[frecv] = st[id];
    }

   if (prim[frmin] == 0 && frmin==frecv) {
        frmin++;
    }
}

void up(int frecv, int id) {
    dr[id] = prim[frecv];
    st[id] = 0;

    if (prim[frecv] != 0) {
        st[prim[frecv]] = id;
    } else {
        ultim[frecv] = id;
    }
    prim[frecv] = id;
}

void kickhash(int hashval, int id) {
    int p;

    if (h[hashval] == id) {
        h[hashval] = nexth[id];
        return;
    }

    p = h[hashval];
    while (p != 0 && nexth[p] != 0) {
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
    frmin = 0;
    for (i=0; i<MOD; i++) {
        h[i] = 0;
    }
    for (i=0; i<NMAX; i++) {
        prim[i] = 0;
        ultim[i] = 0;
    }
}


int get(int x) {
    int hashval, p;

    hashval = (x % MOD + MOD) % MOD;
    p = h[hashval];
    while (p != 0) {
        if (key[p] == x) {
            kicklru(p);
            f[p]++;
            up(f[p], p);
            return val[p];
        }
        p = nexth[p];
    }

    return -1;
}

void put(int x, int y) {
    int hashval, p, newid, oldhashval;

    hashval = (x % MOD + MOD) % MOD;
    p = h[hashval];
    while (p != 0) {
        if (key[p] == x) {
            val[p] = y;
            kicklru(p);
            f[p]++;
            up(f[p], p);
            return;
        }
        p = nexth[p];
    }

    if (n == nmax) {
        newid = ultim[frmin];
        kicklru(newid);
        oldhashval = (key[newid]%MOD+MOD)%MOD;
        kickhash(oldhashval, newid);
    } else {
        n++;
        newid = n;
    }

    key[newid] = x;
    val[newid] = y;
    f[newid] = 1;
    frmin = 1;
    up(1, newid);
    bagahash(hashval, newid);
}

int main() {
    
    return 0;
}