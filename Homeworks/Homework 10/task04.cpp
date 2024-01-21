#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

size_t dfsFindConnectedComponents(const vector<vector<int>>& graph, vector<bool>& visited, int city) {
    size_t result = 1;
    visited[city] = true;
    for (const auto& c : graph[city]) {
        if (!visited[c]) {
            result += dfsFindConnectedComponents(graph, visited, c);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t queriesAmount;
    cin >> queriesAmount;

    size_t citiesAmount, roadsAmount, discoPrice, roadPrice;
    for (size_t i = 0; i < queriesAmount; i++) {
        cin >> citiesAmount >> roadsAmount >> discoPrice >> roadPrice;

        vector<vector<int>> graph(citiesAmount + 1);
        vector<bool> visited(citiesAmount + 1);
        vector<int> connectedComponents;

        for (size_t j = 0; j < roadsAmount; j++) {
            size_t x, y;
            cin >> x >> y;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for (size_t j = 1; j <= citiesAmount; j++) {
            if (!visited[j]) {
                connectedComponents.push_back(dfsFindConnectedComponents(graph, visited, j));
            }
        }

        size_t price = 0;
        for (size_t j = 0; j < connectedComponents.size(); j++) {
            price += min((connectedComponents[j] - 1) * roadPrice + discoPrice, connectedComponents[j] * discoPrice);
        }

        cout << price << endl;
    }

    return 0;
}
