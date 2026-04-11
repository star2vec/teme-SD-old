#include <iostream>

#define NMAX 1001

int v[NMAX];

int in[NMAX], fin[NMAX];
int out[NMAX], fout[NMAX];

int nin, nout;

int f(int x, int y) {
    return x & y;
}

void opin(int x) {
    nin++;
    in[nin] = x;

    if (nin==1) {
        fin[1] = in[1];
        return;
    }
    fin[nin] = f(fin[nin-1], x);
}
void slide() {
    int x;

    if (nout == 0) {
        while (nin > 0) {
            x = in[nin];
            nin--;

            nout++;
            out[nout] = x;
            if (nout == 1) {
                fout[nout] = x;
            } else {
                fout[nout] = f(fout[nout-1], x);
            }
        }
    }
    if (nout>0) {
        nout--;
    }
}

int query() {
    if (nin==0) {
        return fout[nout];
    }
    if (nout==0) {
        return fin[nin];
    }
    return f(fin[nin], fout[nout]);
}


int main() {
    int n, i, k;

    std::cin >> n >> k;
    for (i=0; i<n; i++) {
        std::cin >> v[i];
    }

    for (i=0; i<k; i++) {
        opin(v[i]);
    }

    std::cout << query() << " ";
    for (i=k; i<n; i++) {
        slide();
        opin(v[i]);
        std::cout << query() << " ";
    }

    return 0;
}