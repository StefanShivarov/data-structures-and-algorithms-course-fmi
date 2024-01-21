#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX = 1000000;
size_t parent[MAX], depth[MAX];

size_t Find(size_t x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

bool Union(size_t x, size_t y) {
    size_t root1 = Find(x);
    size_t root2 = Find(y);

    if (root1 == root2) {
        return false;
    }

    if (depth[root1] > depth[root2]) {
        swap(root1, root2);
    }

    if (depth[root1] == depth[root2]) {
        depth[root2]++;
    }

    parent[root1] = root2;
    return true;
}

int main() {
    size_t nodesAmount;
    cin >> nodesAmount;

    for (size_t i = 1; i <= nodesAmount; i++) {
        parent[i] = i;
        depth[i] = 1;
    }

    size_t components = nodesAmount;
    size_t from, to;
    while (cin >> from >> to) {
        if (Union(from, to)) {
            cout << --components << endl;
        }
        else {
            cout << components << " CYCLE FORMED!" << endl;
        }
    }

    return 0;
}
