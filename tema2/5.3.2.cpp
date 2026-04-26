#include <iostream>
#include <deque>

using namespace std;

const int NMAX = 2000002; ///facem de la jumatate, no need for MOD

int deq[NMAX];
int st, dr;

void init() {
    st = NMAX/2-1;
    dr = NMAX/2;
}

void push_front(int x) {
    deq[st] = x;
    st--;
}

void push_back(int x) {
    deq[dr] = x;
    dr++;
}

void pop_front() {
    st++;
}

void pop_back() {
    dr--;
}

int element_at_index(int p) {
    return deq[st+1+p];
}

int main() {
    init();

    return 0;
}