#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

long sumsArr[20000000] = { 0 };
size_t minIndex = 10000000;
size_t maxIndex = 10000000;
Node nodesArr[1000000];

void sumColumns(Node* root, size_t index) {
    if (!root) {
        return;
    }

    sumsArr[index] += root->value;

    if (index < minIndex) {
        minIndex = index;
    }

    if (maxIndex < index) {
        maxIndex = index;
    }

    sumColumns(root->left, index - 1);
    sumColumns(root->right, index + 1);
}


int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int value, leftIndex, rightIndex;
        std::cin >> value >> leftIndex >> rightIndex;

        nodesArr[i].value = value;
        if (leftIndex == -1) {
            nodesArr[i].left = nullptr;
        }
        else {
            nodesArr[i].left = &nodesArr[leftIndex];
        }

        if (rightIndex == -1) {
            nodesArr[i].right = nullptr;
        }
        else {
            nodesArr[i].right = &nodesArr[rightIndex];
        }
    }

    sumColumns(&nodesArr[0], minIndex);

    for (size_t i = minIndex; i <= maxIndex; i++) {
        if (sumsArr[i] != 0) {
            cout << sumsArr[i] << " ";
        }
    }
}
