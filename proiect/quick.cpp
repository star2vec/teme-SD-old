#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ranges>
#include <cstdlib>
#include <ctime>

void quick_sort_rec(std::vector<int>& a, int st, int dr) {
    if (st >= dr) return;

    int pivot_idx = st + std::rand() % (dr - st + 1);
    int pivot = a[pivot_idx];

    int s = st;
    int d = dr;

    while (s <= d) {
        while (a[s] < pivot)
            s++;
        while (a[d] > pivot)
            d--;

        if (s <= d) {
            std::swap(a[s], a[d]);
            s++;
            d--;
        }
    }

    if (st < d)
        quick_sort_rec(a, st, d);
    if (s < dr)
        quick_sort_rec(a, s, dr);
}

void quick_sort(std::vector<int>& a) {
    if (a.empty()) return;
    std::srand(std::time(nullptr));
    quick_sort_rec(a, 0, a.size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }
    quick_sort(a);
    assert(std::ranges::is_sorted(a));

    return 0;
}