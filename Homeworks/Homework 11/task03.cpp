#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

struct Tunnel { int to, weight, kg; };

int maxDistance;
int target, minWeight = -1;

bool hasPathForWeight(vector<deque<Tunnel>>& graph, int kg) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    distances[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);

    size_t newDistance;
    size_t currentNode;

    while (!pq.empty()) {

        currentNode = pq.top().second;
        visited[currentNode] = true;

        if (currentNode == target) {
            break;
        }

        for (auto tunnel = graph[currentNode].begin(); tunnel != graph[currentNode].end(); tunnel++) {

            if (tunnel->kg > kg || visited[tunnel->to]) {
                continue;
            }

            int& distanceToNeighbour = distances[tunnel->to];

            newDistance = distances[currentNode] + tunnel->weight;

            if (newDistance < distanceToNeighbour) {
                pq.emplace(newDistance, tunnel->to);
                distanceToNeighbour = newDistance;
            }
        }

        while (!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
    }

    return distances[target] <= maxDistance;
}

void findMinWeight(vector<deque<Tunnel>>& graph, int lowerBound, int upperBound) {
    if (upperBound < lowerBound) {
        return;
    }

    int mid = lowerBound + (upperBound - lowerBound) / 2;

    if (hasPathForWeight(graph, mid))
    {
        minWeight = mid;
        findMinWeight(graph, lowerBound, mid - 1);
    }
    else {
        findMinWeight(graph, mid + 1, upperBound);
    }
}

int main() {
    int crossroadsAmount, tunnelsAmount;
    cin >> crossroadsAmount >> tunnelsAmount >> maxDistance;

    vector<deque<Tunnel>> graph(crossroadsAmount);
    target = crossroadsAmount - 1;

    int startVertex, maxWeight = INT_MIN;

    Tunnel tunnel;
    for (int i = 0; i < tunnelsAmount; i++) {
        cin >> startVertex >> tunnel.to >> tunnel.kg >> tunnel.weight;
        startVertex--;
        tunnel.to--;
        graph[startVertex].push_back(tunnel);
        maxWeight = max(tunnel.kg, maxWeight);
    }

    findMinWeight(graph, 0, maxWeight);
    cout << minWeight;

    return 0;
}
