#include <iostream>
#include <string>
#include <vector>

#define NMAX 165536

using namespace std;

class hasheala {
private:
    int m;
    int n;
    string h[NMAX];
    int tombstone[NMAX];

    int computehash(const string& s) const {
        int i, hashval, pow27;

        hashval = 0;
        pow27 = 1;
        for (i=0; i<s.length(); i++) {
            hashval = (hashval + (s[i]-'a'+1)*pow27) % m;
            pow27 = (pow27*27)%m;
        }

        return hashval;
    }

    void resize() {
        int mm, hashval, i;

        mm = 2*m;
        vector<string> hvechi;
        for (hashval=0; hashval<m; hashval++) {
            if (tombstone[hashval] == 1) {
                hvechi.push_back(h[hashval]);
            }
        }

        m = mm;
        for (hashval=0; hashval<m; hashval++) {
            tombstone[hashval] = 0;
        }

        n=0;
        for (i=0; i<hvechi.size(); i++) {
            insert(hvechi[i]);
        }
    }

public:
    hasheala(int minit = 128) {
        m = minit;
        n = 0;
        int i;
        for (i=0; i<NMAX; i++) {
            tombstone[i] = 0;
        }
    }

    void insert(const string& s) {
        int hashval;

        hashval = computehash(s);
        if (tombstone[hashval]==0) {
            h[hashval] = s;
            tombstone[hashval] = 1;
            n++;
        } else {
            while (tombstone[hashval]==1) {
                hashval = (hashval+1)%m;
            }
            tombstone[hashval] = 1;
            h[hashval] = s;
            n++;
        }

        if (4*n > 3*m) {
            resize();
        }
    }

    void erase(const string& s) {
        int hashval, ok;

        hashval = computehash(s);
        ok = 0;
        while (tombstone[hashval]!=0 && ok==0) {
            if (tombstone[hashval]==1 && h[hashval]==s) {
                tombstone[hashval] = 2;
                n--;
                ok = 1;
            }
            hashval = (hashval+1)%m;
        }
    }

    int exists(const string& s) const {
        int hashval;

        hashval = computehash(s);
        while (tombstone[hashval]!=0) {
            if (tombstone[hashval]==1 && h[hashval]==s) {
                return 1;
            }
            hashval = (hashval+1)%m;
        }
        return 0;
    }
};
 
int main() {

    return 0;
}
