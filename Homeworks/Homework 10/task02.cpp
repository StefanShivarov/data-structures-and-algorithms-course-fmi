#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <set>

using namespace std;

const size_t SIZE_T_MAX_VAL = numeric_limits<size_t>::max();

unordered_map<size_t, vector<size_t>> graph;

vector<size_t> bfs(size_t start, size_t n) {
    vector<size_t> dist(n + 1, SIZE_T_MAX_VAL);
    queue<size_t> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        size_t current = q.front();
        q.pop();

        for (size_t neighbor : graph[current]) {
            if (dist[neighbor] == SIZE_T_MAX_VAL) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

size_t findSmallestDistanceWithinGroup(size_t groupNumber, size_t n, const vector<size_t>& friendGroups) {
    size_t smallestDistance = SIZE_T_MAX_VAL;

    for (size_t i = 1; i <= n; ++i) {
        if (friendGroups[i] == groupNumber) {
            vector<size_t> dist = bfs(i, n);

            for (size_t j = 1; j <= n; ++j) {
                if (friendGroups[j] == groupNumber && j != i) {
                    if (dist[j] < smallestDistance) {
                        smallestDistance = dist[j];
                    }
                }
            }
        }
    }

    return smallestDistance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    size_t x, y;
    for (size_t i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<size_t> friendGroups(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> friendGroups[i];
    }

    size_t friendGroup;
    cin >> friendGroup;

    size_t smallestDistance = findSmallestDistanceWithinGroup(friendGroup, n, friendGroups);
    if (smallestDistance == SIZE_T_MAX_VAL) {
        cout << -1;
    }
    else {
        cout << smallestDistance;
    }

    return 0;
}
