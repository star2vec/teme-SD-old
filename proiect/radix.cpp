#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ranges>


void counting_sort_for_radix(std::vector<int>& a, std::vector<int>& output, int exp) {
    int n = a.size();
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
void radix_sort(std::vector<int>& a) {
    if (a.empty()) return;
    int max_val = *std::max_element(a.begin(), a.end());
    std::vector<int> output(a.size());
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_for_radix(a, output, exp);
    }
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
    radix_sort(a);
    assert(std::ranges::is_sorted(a));

    return 0;
}