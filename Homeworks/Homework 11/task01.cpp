#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

const size_t SIZE_T_INF = numeric_limits<size_t>::max();

struct Edge {
    size_t to;
    size_t weight;

    bool operator>(const Edge& other) const {
        return this->weight > other.weight;
    }
};

unordered_map<size_t, vector<Edge>> map;

vector<size_t> shortestDistances(size_t start, const vector<size_t>& intervals) {
    vector<size_t> distances(intervals.size(), SIZE_T_INF);
    distances[start] = 0;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        size_t stop = pq.top().to;
        size_t dist = pq.top().weight;
        pq.pop();

        if (dist > distances[stop]) {
            continue;
        }

        for (const auto& neighbour : map[stop]) {
            size_t nextStop = neighbour.to;
            size_t distanceToNextStop = neighbour.weight;
            size_t timeTravelled = dist;
            size_t waitTime = timeTravelled % intervals[stop];
            waitTime = waitTime ? intervals[stop] - waitTime : waitTime;
            timeTravelled += waitTime + distanceToNextStop;

            if (timeTravelled < distances[nextStop]) {
                distances[nextStop] = timeTravelled;
                pq.push({ nextStop, timeTravelled });
            }
        }
    }

    return distances;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t busStopsAmount, roadsAmount, start, end;
    cin >> busStopsAmount >> roadsAmount >> start >> end;
    vector<size_t> intervals(busStopsAmount);

    for (size_t i = 0; i < busStopsAmount; ++i) {
        cin >> intervals[i];
    }

    size_t x, y, distance;
    for (size_t i = 0; i < roadsAmount; ++i) {
        cin >> x >> y >> distance;
        map[x].push_back({ y, distance });
    }

    vector<size_t> distances = shortestDistances(start, intervals);
    if (distances[end] != SIZE_T_INF) {
        cout << distances[end];
    }
    else {
        cout << -1;
    }

    return 0;
}
