#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ranges>


void gnome_sort(std::vector<int>& a) {
    int idx, aux;

    if (a.size()<=1) {
        return;
    }

    idx = 1;
    while (idx<a.size()) {
        if (idx>0 && a[idx-1]>a[idx]) {
            aux = a[idx-1];
            a[idx-1] = a[idx];
            a[idx] = aux;

            idx--;
        } else {
            idx++;
        }
    }

    return;
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
    gnome_sort(a);
    assert(std::ranges::is_sorted(a));

    return 0;
}
