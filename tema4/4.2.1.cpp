#include <iostream>

#define NMAX 250002

int heap[NMAX];
int heapsize;

static inline int parent(int i) {
    return (i-1)/2;
}
static inline int left(int i) {
    return i*2+1;
}
static inline int right(int i) {
    return i*2+2;
}

void downheap(int nod) {
    int aux, st, dr, maxi;
    
    st = left(nod);
    dr = right(nod);
    maxi = nod;
    
    if (st<heapsize && heap[st]>heap[maxi]) {
        maxi = st;
    }
    if (dr<heapsize && heap[dr]>heap[maxi]) {
        maxi = dr;
    }
    
    if (maxi!=nod) {
        aux = heap[maxi];
        heap[maxi] = heap[nod];
        heap[nod] = aux;
        downheap(maxi);
    }
}

void pop() {
    heapsize--;
    heap[0] = heap[heapsize];
    downheap(0);
}

int top() {
    return heap[0];
}


void upheap(int nod) {
    int aux;
    while (nod>0 && heap[parent(nod)]<heap[nod]) {
        aux = heap[nod];
        heap[nod] = heap[parent(nod)];
        heap[parent(nod)] = aux;
        nod = parent(nod);
    }
}

void insert(int val) {
    heap[heapsize] = val;
    heapsize++;
    upheap(heapsize-1);
}


int main() {

    return 0;
}