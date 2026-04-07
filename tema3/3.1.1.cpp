#include <iostream>
#include <string>
#include <list>

#define NMAX 165536

using namespace std;

class hasheala {
private:
    int m;
    int n;
    list<string> h[NMAX];

    int computehash(const string& s) {
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
        int mm, hashval;

        mm = 2*m;
        list<string> hvechi;
        for (hashval=0; hashval<m; hashval++) {
            for (const string& s : h[hashval]) {
                hvechi.push_back(s);
            }
            h[hashval].clear();
        }

        m = mm;
        for (const string& s : hvechi) {
            hashval = computehash(s);
            h[hashval].push_back(s);
        }
    }

public:
    hasheala(int minit = 128) {
        m = minit;
        n = 0;
    }

    void insert(const string& s) {
        int hashval;

        hashval = computehash(s);
        h[hashval].push_back(s);
        n++;

        if (4*n > 3*m) {
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
    
    return 0;
}
