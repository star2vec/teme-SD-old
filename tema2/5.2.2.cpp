#include <iostream>
 
#define NCOADA 4096 /// 4*1000
#define NMAX 1002
#define MUL 1024

int vase[NMAX][NMAX];
int coada[2][NCOADA];
int ultim, prim;
 
static inline void enqueue(int l, int c) {
    coada[0][ultim] = l;
    coada[1][ultim] = c;
    ultim = (ultim+1)%NCOADA;
}
 
static inline int dequeue() {
    int retval;
    
    retval = coada[0][prim] * MUL + coada[1][prim];
    prim = (prim+1)%NCOADA;
    
    return retval;
}

int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

static inline void mutare(int ll, int cc, int dist) {
    if (vase[ll][cc] == 0) {
        enqueue(ll, cc);
        vase[ll][cc] = dist+1;
    }
}
 
 
int main() {
    int a, b, t, l, c, retval, dist, ll, cc, turnat;

    std::cin >> a >> b >> t;

    prim = 0;
    ultim = 0;
    enqueue(0, 0);
    vase[0][0] = 1;
    l = 0;
    c = 0;
    do {
        retval = dequeue();
        l = retval/MUL;
        c = retval%MUL;
        dist = vase[l][c];

        mutare(a, c, dist);
        mutare(l, b, dist);
        mutare(0, c, dist);
        mutare(l, 0, dist);

        turnat = min(l, b-c);
        mutare(l-turnat, c+turnat, dist);

        turnat = min(c, a-l);
        mutare(l+turnat, c-turnat, dist);
    } while (((l!=t) && (c!=t)) && (prim!=ultim));

    if (l==t || c==t) {
        std::cout << vase[l][c]-1;
    } else {
        std::cout << "imposibil :C";
    }


    return 0;
}
