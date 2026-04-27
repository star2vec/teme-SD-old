#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
#include <ranges>

struct card {
    int val;
    int idx;

    bool operator<(const card& other) const {
        return val > other.val;
    }
};

void patience_sort(std::vector<int>& a) {
    std::vector<std::vector<int>> pile;
    int i, j, st, dr, mijl;
    card now;

    pile.push_back({a[0]});

    for (i=1; i<a.size(); i++) {
        st = 0;
        dr = pile.size();
        j = dr;
        while (dr-st>1) {
            mijl = (st+dr)/2;
            if (pile[mijl].back()>a[i]) {
                dr = mijl;
            } else {
                st = mijl;
            }
        }
        if (pile[st].back()>a[i]) {
            j = st;
        }

        if (j<pile.size()) {
            pile[j].push_back(a[i]);
        } else {
            pile.push_back({a[i]});
        }
    }

    std::priority_queue<card> heap;
    for (i=0; i<pile.size(); i++) {
        heap.push({pile[i].back(), i});
        pile[i].pop_back();
    }

    i=0;
    while (heap.size()>0) {
        now = heap.top();
        heap.pop();

        a[i] = now.val;
        i++;

        if (pile[now.idx].size()>0) {
            heap.push({pile[now.idx].back(), now.idx});
            pile[now.idx].pop_back();
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
    patience_sort(a);
    assert(std::ranges::is_sorted(a));

    /*
    for (int& x : a) {
        std::cout << x << ' ';
    }
    */

    return 0;
}