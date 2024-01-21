#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    cin >> n;

    unordered_map<size_t, size_t> map;
    size_t minDistance = numeric_limits<size_t>::max();
    size_t previousIndex = 0, currentIndex = 0;

    for (size_t i = 0; i < n; i++) {
        size_t granny;
        cin >> granny;

        if (map.find(granny) != map.end()) {
            currentIndex = i;
            previousIndex = map[granny];
            minDistance = min(minDistance, (currentIndex - previousIndex));
        }

        map[granny] = i;
    }

    if (minDistance == numeric_limits<size_t>::max()) {
        cout << -1;
    }
    else {
        cout << minDistance;
    }

    return 0;
}