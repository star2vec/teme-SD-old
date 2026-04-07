///acelasi cod ca cel de la 3.1.1 in mare parte, se potrivea partea cu stringul

#include <iostream>
#include <string>
#include <list>

#define NMAX 165536

using namespace std;

class hasheala {
private:
    int mhash;
    int n;
    list<string> h[NMAX];

    int computehash(const string& s) {
        int i, hashval;

        hashval = 0;
        for (i=0; i<s.length(); i++) {
            hashval = (hashval * 27 + (s[i] - 'a' + 1)) % mhash;
        }

        return hashval;
    }

    void resize() {
        int mm, hashval;

        mm = 2*mhash;
        list<string> hvechi;
        for (hashval=0; hashval<mhash; hashval++) {
            for (const string& s : h[hashval]) {
                hvechi.push_back(s);
            }
            h[hashval].clear();
        }

        mhash = mm;
        for (const string& s : hvechi) {
            hashval = computehash(s);
            h[hashval].push_back(s);
        }
    }

public:
    hasheala(int minit = 128) {
        mhash = minit;
        n = 0;
    }

    void insert(const string& s) {
        int hashval;

        hashval = computehash(s);
        h[hashval].push_back(s);
        n++;

        if (4*n > 3*mhash) {
            resize();
        }
    }

    void erase(const string& s) {
        int hashval;
        hashval = computehash(s);
        h[hashval].remove(s);
        n--;
    }

    int exists(const string& s) {
        int i, hashval, found;

        hashval = computehash(s);
        for (const string& element : h[hashval]) {
            if (element == s) {
                return 1;
            }
        }
        return 0;
    }
};
 
int main() {
    int ncuv, mcuv, i;
    int mhash;
    string cuv;

    cin >> ncuv >> mcuv;
    mhash = ncuv*2;
    hasheala* h = new hasheala(mhash);

    for (i=0; i<ncuv; i++) {
        cin >> cuv;
        h->insert(cuv);
    }

    
    delete h;

    return 0;
}
