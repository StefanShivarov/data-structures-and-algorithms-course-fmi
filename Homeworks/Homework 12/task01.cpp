#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000000;

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

    if (depth[root1] > depth[root2]) {
        swap(root1, root2);
    }

    if (depth[root1] == depth[root2]) {
        depth[root2]++;
    }

    parent[root1] = root2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodesAmount, edgesAmount;
    cin >> nodesAmount >> edgesAmount;

    for (int i = 1; i <= nodesAmount; i++) {
        parent[i] = i;
        depth[i] = 1;
    }

    int from, to;
    for (int i = 0; i < edgesAmount; i++) {
        cin >> from >> to;
        Union(from, to);
    }

    int queriesAmount;
    cin >> queriesAmount;
    vector<bool> output(queriesAmount);

    int queryType, queryFrom, queryTo, questionsAmount = 0;
    for (int i = 0; i < queriesAmount; i++) {
        cin >> queryType >> queryFrom >> queryTo;

        if (queryType == 1) {
            output[questionsAmount++] = (Find(queryFrom) == Find(queryTo));
        }
        else {
            Union(queryFrom, queryTo);
        }
    }

    for (int i = 0; i < questionsAmount; i++) {
        cout << output[i];
    }

    return 0;
}
