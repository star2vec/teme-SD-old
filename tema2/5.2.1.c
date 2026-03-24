#include <stdio.h>
 
#define NCOADA 700 /// 4*175
 
int a[177][177];
int coada[2][NCOADA]; /// 0 - linie; 1 - coloana
int ultim, prim;
int dlin[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};
 
static inline void enqueue(int l, int c) {
    coada[0][ultim] = l;
    coada[1][ultim] = c;
    ultim = (ultim+1)%NCOADA;
}
 
static inline int dequeue() {
    int retval;
    
    retval = coada[0][prim] * 256 + coada[1][prim];
    prim = (prim+1)%NCOADA;
    
    return retval;
}
 
 
int main() {
    FILE *fin, *fout;
    fin = fopen("alee.in", "r");
    fout = fopen("alee.out", "w");
    
    int n, m, i, l, c, lstart, cstart, lend, cend, retval, dist, ll, cc;
    
    fscanf(fin, "%d%d", &n, &m);
 
    for (i=0; i<m; i++) {
        fscanf(fin, "%d%d", &l, &c);
        a[l][c] = -1;
    }
    
    ///bordare
    for (i=0; i<=n+1; i++) {
        a[i][0] = a[i][n+1] = a[0][i] = a[n+1][i] = -1;
    }
    
    fscanf(fin, "%d%d%d%d", &lstart, &cstart, &lend, &cend);
 
 
    prim = 0;
    ultim = 0;
    enqueue(lstart, cstart);
    
    a[lstart][cstart] = 1;
 
    l=lstart;
    c=cstart;
    do {
        retval = dequeue();
        l = retval/256;
        c = retval%256;
        dist = a[l][c];
        ll=l;
        cc=c;
        for (i=0; i<4; i++) {
            ll = l + dlin[i];
            cc = c + dcol[i];
            if (a[ll][cc] == 0) {
                enqueue(ll, cc);
                a[ll][cc] = dist+1;
            }
        }
    } while ((l!=lend) || (c!=cend));
    
    fprintf(fout, "%d", a[lend][cend]);
    
    fclose(fin);
    fclose(fout);
    return 0;
}
