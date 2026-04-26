#include <iostream>
#include <stdio.h>

#define NMAX 1002
#define MOD 87657643

using namespace std;

int lft[NMAX];
int rght[NMAX];
int root;
int n;

int dpr[NMAX][NMAX];
int dpb[NMAX][NMAX];

int hmax[NMAX];

void dp(int nod) {
    int st, dr, hstmax, hdrmax, hst, hdr, h;
    long long int nrr, nrb, dprst, dprdr, dpbst, dpbdr, dpst, dpdr;

    if (nod == -1) {
        return;
    }

    st = lft[nod];
    dp(st);
    dr = rght[nod];
    dp(dr);

    if (st!=-1) {
        hstmax = hmax[st];
    } else {
        hstmax = 0;
    }
    if (dr!=-1) {
        hdrmax = hmax[dr];
    } else {
        hdrmax = 0;
    }
    hmax[nod] = max(hstmax, hdrmax)+1;

    for (hst=0; hst<=hstmax; hst++) {

        if (st==-1) {
            dprst = 0;
            dpbst = 0;
            if (hst==0) {
                dpbst++;
            }
        } else {
            dprst = dpr[st][hst];
            dpbst = dpb[st][hst];
        }
        dpst = (dprst+dpbst)%MOD;

        for (hdr=max(0, hst-1); hdr<=min(hdrmax, hst+1); hdr++) {
            if (dr==-1) {
                dprdr = 0;
                dpbdr = 0;
                if (hdr==0) {
                    dpbdr++;
                }
            } else {
                dprdr = dpr[dr][hdr];
                dpbdr = dpb[dr][hdr];
            }
            dpdr = (dprdr+dpbdr)%MOD;

            h = max(hst, hdr);


            nrr = (dpbst*dpbdr)%MOD;
            dpr[nod][h] = (dpr[nod][h] + nrr)%MOD;

            nrb = (dpst*dpdr)%MOD;
            dpb[nod][h+1] = (dpb[nod][h+1] + nrb)%MOD;
        }
    }
}

int main() {
    int i, h;
    long long int rez;

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> lft[i] >> rght[i];
    }

    root = 0;
    dp(root);

    rez = 0;
    for (h=0; h<=hmax[root]+1; h++) {
        rez = (rez + dpr[root][h] + dpb[root][h])%MOD;
    }
    cout << rez << "\n";

    return 0;
}