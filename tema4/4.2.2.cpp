#include <iostream>

#define NMAX 250002
#define KMAX 101
#define LMAX 50

int heap[NMAX];
int heapidx[NMAX];
int heapsize;

int k, n;
int l[KMAX][LMAX];
int next[KMAX][LMAX];
int rez[NMAX];
int pas[NMAX];

static inline int parent(int i) {
    return (i-1)/2;
}
static inline int left(int i) {
    return i*2+1;
}
static inline int right(int i) {
    return i*2+2;
}

void downheap(int poz) {
    int aux, st, dr, mini;

    st = left(poz);
    dr = right(poz);
    mini = poz;

    if (st<heapsize && heap[st]<heap[mini]) {
        mini = st;
    }
    if (dr<heapsize && heap[dr]<heap[mini]) {
        mini = dr;
    }

    if (mini!=poz) {
        aux = heap[mini];
        heap[mini] = heap[poz];
        heap[poz] = aux;

        aux = heapidx[mini];
        heapidx[mini] = heapidx[poz];
        heapidx[poz] = aux;

        downheap(mini);
    }
}

void pop() {
    heapsize--;
    heap[0] = heap[heapsize];
    heapidx[0] = heapidx[heapsize];
    downheap(0);
}

int top() {
    return heap[0];
}

void upheap(int poz) {
    int aux;
    while (poz>0 && heap[parent(poz)]>heap[poz]) {
        aux = heap[poz];
        heap[poz] = heap[parent(poz)];
        heap[parent(poz)] = aux;

        aux = heapidx[poz];
        heapidx[poz] = heapidx[parent(poz)];
        heapidx[parent(poz)] = aux;

        poz = parent(poz);
    }
}

void insert(int val, int idx) {
    heap[heapsize] = val;
    heapidx[heapsize] = idx;
    heapsize++;
    upheap(heapsize-1);
}

void build() {
    int i, idx;

    for (i=0; i<k; i++) {
        insert(l[i][0], i);
    }

    i = 0;
    while (heapsize > 0) {
        rez[i] = top();
        i++;

        idx = heapidx[0];

        if (next[idx][pas[idx]]!=-1) {
            pas[idx] = next[idx][pas[idx]];
            heap[0] = l[idx][pas[idx]];
            heapidx[0] = idx;
            downheap(0);
        } else {
            pop();
        }
    }
}

int main() {

    return 0;
}