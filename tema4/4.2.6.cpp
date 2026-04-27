#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 100001
#define BITMAX 22

int v[NMAX];
int sp[BITMAX][NMAX];

int val[BITMAX+1];
int f[BITMAX+1];
int nr;

int newval[BITMAX+1];
int newf[BITMAX+1];
int newnr;


int main() {
    ifstream fin("sufle.in");
    ofstream fout("sufle.out");

    int n, q, i, p, aux, qq, st, dr, lung, fp, rem;
    long long int rez;

    fin >> n >> q;
    for (i=1; i<=n; i++) {
        fin >> v[i];
        for (p=0; p<BITMAX; p++) {
            sp[p][i] = sp[p][i-1] + (v[i]>>p)%2;
        }
    }

    for (qq=0; qq<q; qq++) {
        fin >> st >> dr;

        f[0] = dr-st+1;
        val[0] = 0;
        nr = 1;

        for (p=BITMAX-1; p>=0; p--) {
            fp = sp[p][dr]-sp[p][st-1];

            if (fp!=0) {
                newnr = 0;
                rem = fp;

                for (i=0; i<nr; i++) {
                    if (rem == 0) {
                        newval[newnr] = val[i];
                        newf[newnr] = f[i];
                        newnr++;
                    } else if (f[i]<=rem) {
                        val[i] = val[i] | (1LL << p);
                        newval[newnr] = val[i];
                        newf[newnr] = f[i];
                        newnr++;
                        rem = rem-f[i];
                    } else {
                        newval[newnr] = val[i];
                        newf[newnr] = f[i]-rem;
                        newnr++;
                        newval[newnr] = val[i] | (1LL << p);
                        newf[newnr] = rem;
                        newnr++;
                        rem = 0;
                    }
                }

                nr = newnr;
                for (i=0; i<newnr; i++) {
                    val[i] = newval[i];
                    f[i] = newf[i];
                }
            }
        }

        rez = 0;
        for (i=0; i<nr; i++) {
            rez += 1LL*f[i]*val[i]*val[i];
        }

        fout << rez << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}