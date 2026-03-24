#include <iostream>
#include <fstream>

using namespace std;

const int NMAX = 1002;

int st[NMAX];
int a[NMAX][NMAX];

int up[NMAX][NMAX];

int lft[NMAX];
int rght[NMAX];

int main() {
    ifstream fin("fadema.in");
    ofstream fout("fadema.out");
    int n, m, l, c, k, area, amax, zid;

    fin >> n >> m;

    for (l=1; l<=n; l++) {
        for (c=1; c<=m; c++) {
            fin >> a[l][c];
        }
    }

    for (c=1; c<=m; c++) {
        up[n][c] = 1;
        for (l=n-1; l>=1; l--) {
            if (a[l][c] != a[l+1][c]) {
                up[l][c] = up[l+1][c]+1;
            } else {
                up[l][c] = 1;
            }
        }
    }

    amax = 0;
    for (l=1; l<=n; l++) {
        a[l][0] = -1;
        zid = 0;
        k = 0;
        for (c=1; c<=m; c++) {
            if (c>1 && a[l][c]==a[l][c-1]) {
                zid = c-1;
                k = 0;
            }
            while (k>0 && up[l][c]<=up[l][st[k-1]]) {
                k--;
            }
            if (k==0) {
                lft[c] = zid;
            } else {
                lft[c] = st[k-1];
            }
            st[k] = c;
            k++;
        }

        a[l][m+1] = -1;
        zid = m+1;
        k = 0;
        for (c=m; c>=1; c--) {
            if (c<m && a[l][c]==a[l][c+1]) {
                zid = c+1;
                k = 0;
            }
            while (k>0 && up[l][c]<=up[l][st[k-1]]) {
                k--;
            }
            if (k==0) {
                rght[c] = zid;
            } else {
                rght[c] = st[k-1];
            }
            st[k] = c;
            k++;
        }

        for (c=1; c<=m; c++) {
            area = up[l][c]*(rght[c]-lft[c]-1);
            if (amax < area) {
                amax = area;
            }
        }
    }

    fout << amax << '\n';

    fin.close();
    fout.close();
    return 0;
}