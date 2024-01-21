#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int parent[MAX], depth[MAX];

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);

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

struct Edge {
    int from;
    int to;
    int speed;

    bool operator<(const Edge& other) const {
        return speed < other.speed;
    }
};

Edge edges[MAX];

int main() {
    int nodesAmount, edgesAmount;
    cin >> nodesAmount >> edgesAmount;

    int from, to, speed;
    for (int i = 0; i < edgesAmount; i++) {
        cin >> from >> to >> speed;
        edges[i] = { from, to, speed };
    }

    sort(edges, edges + edgesAmount, less<Edge>());

    int minSpeed = 0;
    int maxSpeed = INT_MAX;
    for (int i = 0; i < edgesAmount; i++) {
        for (int j = 0; j <= nodesAmount; j++) {
            parent[j] = j;
        }

        int count = 0, currentMin = edges[i].speed, currentMax = edges[i].speed;
        int difference = maxSpeed - minSpeed;
        for (int j = i; j < edgesAmount; j++) {
            if (Union(edges[j].from, edges[j].to)) {
                count++;
                currentMax = max(currentMax, edges[j].speed);
            }

            if (difference <= currentMax - currentMin) {
                break;
            }
        }

        if (difference <= currentMax - currentMin || count != nodesAmount - 1) {
            continue;
        }

        minSpeed = currentMin;
        maxSpeed = currentMax;
    }

    cout << minSpeed << ' ' << maxSpeed;

    return 0;
}
