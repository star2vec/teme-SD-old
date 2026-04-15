#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define NMAX 50001
#define INF 1000000001

struct muchie {
    int nod, cost;
};

int n, m;
vector<muchie> graf[NMAX];

int dist[NMAX];

muchie heap[NMAX];
int grafnodheap[NMAX];
int heapsize;

static inline int parent(int i) {
    return (i - 1) / 2;
}
static inline int left(int i) {
    return i * 2 + 1;
}
static inline int right(int i) {
    return i * 2 + 2;
}

void downheap(int poz) {
    int st, dr, mini;
    muchie aux;

    st = left(poz);
    dr = right(poz);
    mini = poz;

    if (st < heapsize && heap[st].cost < heap[mini].cost) {
        mini = st;
    }
    if (dr < heapsize && heap[dr].cost < heap[mini].cost) {
        mini = dr;
    }

    if (mini != poz) {
        aux = heap[mini];
        heap[mini] = heap[poz];
        heap[poz] = aux;

        grafnodheap[heap[mini].nod] = mini;
        grafnodheap[heap[poz].nod] = poz;

        downheap(mini);
    }
}

void pop() {
    grafnodheap[heap[0].nod] = -1;
    heapsize--;

    if (heapsize > 0) {
        heap[0] = heap[heapsize];
        grafnodheap[heap[0].nod] = 0;
        downheap(0);
    }
}

muchie top() {
    return heap[0];
}

void upheap(int poz) {
    muchie aux;

    while (poz > 0 && heap[parent(poz)].cost > heap[poz].cost) {
        aux = heap[poz];
        heap[poz] = heap[parent(poz)];
        heap[parent(poz)] = aux;

        grafnodheap[heap[poz].nod] = poz;
        grafnodheap[heap[parent(poz)].nod] = parent(poz);

        poz = parent(poz);
    }
}

void insert(int nod, int cost) {
    heap[heapsize].nod = nod;
    heap[heapsize].cost = cost;
    grafnodheap[nod] = heapsize;
    heapsize++;
    upheap(heapsize - 1);
}

void updateHeap(int nod, int cost) {
    int idx;
    idx = grafnodheap[nod];
    heap[idx].cost = cost;
    upheap(idx);
}

void dijkstra(int start) {
    int i;
    muchie topmuchie, edge;

    for (i = 0; i < n; i++) {
        grafnodheap[i] = -1;
        dist[i] = INF;
    }

    insert(start, 0);
    dist[start] = 0;

    while (heapsize > 0) {
        topmuchie = top();
        pop();

        for (i = 0; i < (int)graf[topmuchie.nod].size(); i++) {
            edge = graf[topmuchie.nod][i];
            if (dist[edge.nod] > dist[topmuchie.nod] + edge.cost) {
                dist[edge.nod] = dist[topmuchie.nod] + edge.cost;

                if (grafnodheap[edge.nod] != -1) {
                    updateHeap(edge.nod, dist[edge.nod]);
                } else {
                    insert(edge.nod, dist[edge.nod]);
                }
            }
        }
    }
}

int main() {

    return 0;
}