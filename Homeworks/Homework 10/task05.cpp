#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const size_t SIZE_T_MAX_VAL = numeric_limits<size_t>::max();

void findLightestRoute(const vector<vector<pair<size_t, size_t>>>& graph, size_t startNode, size_t endNode) {
    size_t nodesAmount = graph.size();

    vector<size_t> distance(nodesAmount, SIZE_T_MAX_VAL);
    vector<size_t> parent(nodesAmount, SIZE_T_MAX_VAL);

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    pq.push({ 0, startNode });
    distance[startNode] = 0;

    while (!pq.empty()) {
        size_t u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            size_t v = edge.first;
            size_t weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({ distance[v], v });
            }
        }
    }

    if (distance[endNode] == SIZE_T_MAX_VAL) {
        cout << -1;
    }
    else {
        cout << distance[endNode];
    }
}

int main() {
    size_t nodesAmount, edgesAmount;
    cin >> nodesAmount >> edgesAmount;
    vector<vector<pair<size_t, size_t>>> graph(nodesAmount + 1);

    for (size_t i = 0; i < edgesAmount; i++) {
        size_t x, y, weight;
        cin >> x >> y >> weight;

        graph[x].push_back({ y, weight });
        graph[y].push_back({ x, weight });
    }

    size_t startIndex, endIndex;
    cin >> startIndex >> endIndex;

    findLightestRoute(graph, startIndex, endIndex);

    return 0;
}
