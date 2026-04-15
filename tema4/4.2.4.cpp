#include <iostream>

#define NMAX 1001

int d[NMAX];
int n;

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

void downheap(int poz) {
    int aux, st, dr, maxi;
    
    st = left(poz);
    dr = right(poz);
    maxi = poz;
    
    if (st<heapsize && heap[st]<heap[maxi]) {
        maxi = st;
    }
    if (dr<heapsize && heap[dr]<heap[maxi]) {
        maxi = dr;
    }
    
    if (maxi!=poz) {
        aux = heap[maxi];
        heap[maxi] = heap[poz];
        heap[poz] = aux;

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


void upheap(int poz) {
    int aux;
    while (poz>0 && heap[parent(poz)]>heap[poz]) {
        aux = heap[poz];
        heap[poz] = heap[parent(poz)];
        heap[parent(poz)] = aux;

        poz = parent(poz);
    }
}

void insert(int val) {
    heap[heapsize] = val;
    heapsize++;
    upheap(heapsize-1);
}


int main() {
    int i, nou, cmin;

    std::cin>>n;
    for (i=0; i<n; i++) {
        std::cin >> d[i];
        insert(d[i]);
    }

    cmin = 0;
    while (heapsize>1) {
        nou = top();
        pop();
        nou+=top();
        cmin = cmin+nou;

        heap[0] = nou;
        downheap(0);
    }
    std::cout << cmin;

    return 0;
}