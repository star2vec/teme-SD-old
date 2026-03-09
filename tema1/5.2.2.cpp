/// bazata pe solutia de la 5.2.1
#include <iostream>
#include <random>

using namespace std;

int* vec;
int size = 0;
int capacity = 0;

void init() {
    vec = new int[2];
    capacity = 2;
}

int get_size() {
    return size;
}

void pop_back() {
    size--;
}

void resize() {
    int i;
    int* newvec = new int[2*capacity];

    capacity *= 2;
    for (i=0; i<size; i++) {
        newvec[i] = vec[i];
    }

    delete[] vec;
    vec = newvec;
}

void push_back(int x) {
    if (size==capacity) {
        resize();
    }
    vec[size] = x;
    size++;
}

//------------------//

void insert(int x) {
    push_back(x);
}

int pop() {
    int idx, elem;

    idx = rand()%size;
    elem = vec[idx];
    cout << elem << ' ';

    vec[idx] = vec[size-1];
    size--;

    return elem;
}

int main() {
    int i, n;

    init();

    insert(1);
    insert(2);
    insert(4);
    insert(8);
    insert(16);

    cout << get_size() << '\n';

    pop();
    pop();
    pop();

    cout << '\n' << get_size() << '\n';

    n = get_size();
    for (i=0; i<n; i++) {
        cout << vec[i] << " ";
    }

    return 0;
}