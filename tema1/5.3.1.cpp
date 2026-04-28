#include<iostream>

int lista[1001];
int next[1001];
int n;

void insertbeg(int k) {
    next[n] = next[0];
    next[0] = n;
    lista[n] = k;
    n++;
}

void delbeg() {
    next[0] = next[next[0]];
}

void insertend(int k) {
    int i;

    lista[n] = k;
    next[n] = -1;

    i=0;
    while (next[i]!=-1) {
        i = next[i];
    }
    next[i] = n;

    n++;
}

void delend() {
    int i;

    i=0;
    while (next[next[i]]!=-1) {
        i = next[i];
    }
    next[i] = -1;
}

int findidx(int poz) {
    int i, idx;
    i=0;
    idx = i;
    while (i<poz && idx!=-1) {
        idx = next[idx];
        i++;
    }
    return lista[idx];
}

int findval(int val) {
    int idx, i;
    idx = 0;
    i=0;
    while (lista[idx]!=val && idx!=-1) {
        idx = next[idx];
        i++;
    }
    return i;
}

void insertpoz(int poz, int val) {
    int i, idx;

    i = 0;
    idx = 0;
    while (i<poz && idx!=-1) {
        idx = next[idx];
        i++;
    }
    if (idx!=-1) {
        next[n] = next[idx];
        next[idx] = n;
        lista[n] = val;
        n++;
    }
}

void delpoz(int poz) {
    int i, idx;

    i = 0;
    idx = 0;
    while (i<poz && idx!=-1) {
        idx = next[idx];
        i++;
    }

    if (idx!=-1) {
        next[idx] = next[next[idx]];
    }
}

void coutlista() {
    int idx;
    idx = next[0];
    while (idx != -1) {
        std::cout << lista[idx] << " ";
        idx = next[idx];
    }
    std::cout << '\n';
}

int main() {
    int idx, val;
    n=1;
    next[0] = -1;

    insertbeg(1);
    insertbeg(2);
    insertend(4);
    insertend(8);
    insertend(16);

    coutlista();

    delbeg();
    delend();
    coutlista();

    val = 8;
    std::cout << findval(val);

    return 0;
}
