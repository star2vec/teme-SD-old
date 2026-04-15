#include <iostream>

#define NMAX 250002

int minheap[NMAX];
int minsize;

int maxheap[NMAX];
int maxsize;

static inline int parent(int i) {
    return (i-1)/2;
}
static inline int left(int i) {
    return i*2+1;
}
static inline int right(int i) {
    return i*2+2;
}

void downmaxheap(int poz) {
    int aux, st, dr, maxi;
    
    st = left(poz);
    dr = right(poz);
    maxi = poz;
    
    if (st<maxsize && maxheap[st]>maxheap[maxi]) {
        maxi = st;
    }
    if (dr<maxsize && maxheap[dr]>maxheap[maxi]) {
        maxi = dr;
    }
    
    if (maxi!=poz) {
        aux = maxheap[maxi];
        maxheap[maxi] = maxheap[poz];
        maxheap[poz] = aux;
        downmaxheap(maxi);
    }
}

void popmax() {
    maxsize--;
    maxheap[0] = maxheap[maxsize];
    downmaxheap(0);
}

int topmax() {
    return maxheap[0];
}


void upmaxheap(int poz) {
    int aux;
    while (poz>0 && maxheap[parent(poz)]<maxheap[poz]) {
        aux = maxheap[poz];
        maxheap[poz] = maxheap[parent(poz)];
        maxheap[parent(poz)] = aux;
        poz = parent(poz);
    }
}

void insertmax(int val) {
    maxheap[maxsize] = val;
    maxsize++;
    upmaxheap(maxsize-1);
}








void downminheap(int poz) {
    int aux, st, dr, mini;

    st = left(poz);
    dr = right(poz);
    mini = poz;

    if (st<minsize && minheap[st]<minheap[mini]) {
        mini = st;
    }
    if (dr<minsize && minheap[dr]<minheap[mini]) {
        mini = dr;
    }

    if (mini!=poz) {
        aux = minheap[mini];
        minheap[mini] = minheap[poz];
        minheap[poz] = aux;
        downminheap(mini);
    }
}


void popmin() {
    minsize--;
    minheap[0] = minheap[minsize];
    downminheap(0);
}

int topmin() {
    return minheap[0];
}


void upminheap(int poz) {
    int aux;
    while (poz>0 && minheap[parent(poz)]>minheap[poz]) {
        aux = minheap[poz];
        minheap[poz] = minheap[parent(poz)];
        minheap[parent(poz)] = aux;
        poz = parent(poz);
    }
}

void insertmin(int val) {
    minheap[minsize] = val;
    minsize++;
    upminheap(minsize-1);
}


void insert(int val) {
    if (val<=topmax()) {
        insertmax(val);
    } else {
        insertmin(val);
    }

    if (maxsize > minsize+1) {
        insertmin(topmax());
        popmax();
    } else if (minsize > maxsize) {
        insertmax(topmin());
        popmin();
    }
}

int mediana() {
    return topmax();
}

int main() {

    return 0;
}