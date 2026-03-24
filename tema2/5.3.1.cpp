#include <iostream>
#include <deque>

using namespace std;

const int NMAX = 5000001;

deque<int> coada;
int v[NMAX];


int main() {

    int n, k, i, j, a, b;

    cin >> n >> k;
    for (i=0; i<n; i++) {
        cin >> v[i];
    }

    for (i=0; i<n; i++) {
        while (coada.empty()==0 && v[i]<v[coada.front()]) {
            coada.pop_front();
        }

        coada.push_front(i);
        if (i>=k-1) {
            if (coada.back()==i-k) {
                coada.pop_back();
            }
            cout << v[coada.back()] << ' ';
        }
    }

    return 0;
}