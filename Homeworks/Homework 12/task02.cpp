#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
const int INF = 1000000000;

struct Edge {
    int index;
    int from;
    int to;
    long long work;
    long long profit;

    bool operator<(const Edge& other) const {
        if (this->work == other.work) {
            return this->profit > other.profit;
        }
        return this->work < other.work;
    }
};

int parent[MAX], depth[MAX];

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);
    if (root1 == root2) {
        return;
    }
    if (depth[root1] > depth[root2])
        swap(root1, root2);
    if (depth[root1] == depth[root2]) {
        depth[root2]++;
    }
    parent[root1] = root2;
}

vector<int> Kruskal(int n, int m, vector<Edge>& edges) {
    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        depth[i] = 1;
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; ++i) {
        int root1 = Find(edges[i].from);
        int root2 = Find(edges[i].to);
        if (root1 != root2) {
            Union(root1, root2);
            //cout << edges[i].index << endl;
            indices.push_back(edges[i].index);
        }
    }

    sort(indices.begin(), indices.end());

    return indices;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodesAmount, edgesAmount;
    cin >> nodesAmount >> edgesAmount;

    vector<Edge> edges;

    int from, to;
    long long work, profit;
    for (int i = 1; i <= edgesAmount; i++) {
        cin >> from >> to >> work >> profit;

        edges.push_back({ i, from, to, work, profit });
    }

    vector<int> output = Kruskal(nodesAmount, edgesAmount, edges);


    for (int i = 0; i < nodesAmount - 1; i++) {
        cout << output[i] << endl;
    }

    return 0;
}
