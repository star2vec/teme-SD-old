#include <iostream>
#include <string>
#include <list>

using namespace std;

#define NMAX 1002
#define LUNGMAX 100
#define MOD 16536

string v[NMAX];
int n;

list<string> h[MOD];
int nr[MOD];

int computehash(const string& s) {
    int hashval, i;

    hashval = 0;
    for (i=0; i<s.size(); i++) {
        hashval = (hashval*2+s[i])%MOD;
    }

    return hashval;
}

int check (int k) {
    int i, j, hashval, pow2, found, newnr;
    string subsir;

    for (i=0; i<MOD; i++) {
        h[i].clear();
    }

    pow2 = 1;
    for (i=0; i<k-1; i++) {
        pow2 = (pow2 * 2) % MOD;
    }

    hashval = 0;
    for (j=0; j<k; j++) {
        hashval = (hashval*2 + (v[0][j]-'0')) % MOD;
    }

    j=0;
    do {
        subsir = v[0].substr(j, k);

        found = 0;
        for (string& s : h[hashval]) {
            if (s == subsir) {
                found = 1;
            }
        }
        if (found == 0) {
            h[hashval].push_back(subsir);
        }

        if (j+k < v[0].size()) {
            hashval = (hashval - (int(v[0][j]-'0') * pow2)%MOD + MOD) % MOD;
            hashval = (hashval*2 + int(v[0][j+k]-'0')) % MOD;
        }
        j++;
    } while (j <= v[0].size() - k);

    for (i=1; i<n; i++) {
        list<string> hh[MOD];

        newnr = 0;
        hashval = 0;
        for (j=0; j<k; j++) {
            hashval = (hashval*2 + (v[i][j]-'0')) % MOD;
        }

        j = 0;
        do {
            subsir = v[i].substr(j, k);

            found = 0;
            for (string& s : h[hashval]) {
                if (s == subsir) {
                    found = 1;
                }
            }
            if (found == 1) {
                found = 0;
                for (string& s : hh[hashval]) {
                    if (s == subsir) {
                        found = 1;
                    }
                }
                if (found == 0) {
                    hh[hashval].push_back(subsir);
                    newnr++;
                }
            }

            if (j+k < v[i].size()) {
                hashval = (hashval - (int(v[i][j]-'0') * pow2)%MOD + MOD) % MOD;
                hashval = (hashval*2 + int(v[i][j+k]-'0')) % MOD;
            }
            j++;
        } while (j <= v[i].size() - k);

        for (j=0; j<MOD; j++) {
            h[j] = hh[j];
        }

        if (newnr==0) {
            return 0;
        }
    }

    return 1;
}


int main() {
    int i, lmin, st, dr, mijl;

    cin >> n;

    lmin = LUNGMAX;
    for (i=0; i<n; i++) {
        cin >> v[i];
        if (lmin>v[i].size()) {
            lmin = v[i].size();
        }
    }

    st = 0;
    dr = lmin+1;
    while (dr-st>1) {
        mijl = (st+dr)/2;
        if (check(mijl)==0) {
            dr = mijl;
        } else {
            st = mijl;
        }
    }

    cout << st;
    
    return 0;
}
