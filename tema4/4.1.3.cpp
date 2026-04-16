#include <iostream>

#define NMAX 1002

int bst[NMAX];
int st[NMAX];
int dr[NMAX];
int dad[NMAX];
int treesize;
int root;

int first;
int second;
int ant;


void inorder(int idx) {
    if (idx == -1) {
        return;
    }

    inorder(st[idx]);

    if (ant!=-1 && bst[ant]>bst[idx]) {
        if (first == -1) {
            first = ant;
            second = idx;
        } else {
            second = idx;
        }
    }
    ant = idx;

    inorder(dr[idx]);
}

void recover() {
    int aux;

    first = -1;
    second = -1;
    ant = -1;

    inorder(root);

    aux = bst[first];
    bst[first] = bst[second];
    bst[second] = aux;
}

int main() {

    return 0;
}