#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

unordered_map<char, set<char>> graph;
bool visited[128];
stack<char> alphabet;

void dfs(const char& symbol) {
    visited[symbol] = true;

    if (graph.count(symbol) == 1) {
        for (const auto& element : graph[symbol]) {
            if (!visited[element]) {
                dfs(element);
            }
        }
    }

    alphabet.push(symbol);
}

void sortAlphabet() {
    for (const auto& element : graph) {
        if (!visited[element.first]) {
            dfs(element.first);
        }
    }
}

int main() {
    size_t n;
    cin >> n;

    string firstWord;
    cin >> firstWord;
    for (size_t i = 1; i < n; i++) {
        string nextWord;
        cin >> nextWord;
        for (size_t j = 0; j < firstWord.size() && j < nextWord.size(); j++) {
            if (firstWord[j] != nextWord[j]) {
                graph[firstWord[j]].insert(nextWord[j]);
                break;
            }
        }
        firstWord = nextWord;
    }

    sortAlphabet();
    while (!alphabet.empty()) {
        cout << alphabet.top() << " ";
        alphabet.pop();
    }

    return 0;
}
