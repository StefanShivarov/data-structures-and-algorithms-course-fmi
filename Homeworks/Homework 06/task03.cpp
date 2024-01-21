#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node() : Node(0) {}
    Node(int value) : Node(value, nullptr, nullptr) {}
    Node(int value, Node* l, Node* r) : val(value), left(l), right(r) {}
};

int findMaxPath(Node* root, int& maxSum) {
    if (!root) {
        return 0;
    }

    int leftSum = max(findMaxPath(root->left, maxSum), 0);
    int rightSum = max(findMaxPath(root->right, maxSum), 0);

    int currentSum = root->val + leftSum + rightSum;
    maxSum = max(maxSum, currentSum);

    return root->val + max(leftSum, rightSum);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Node* nodes = new Node[N];

    for (int i = 0; i < N; ++i) {
        int val, leftIndex, rightIndex;
        cin >> val >> leftIndex >> rightIndex;

        nodes[i] = Node(val);
        if (leftIndex == -1) {
            nodes[i].left = nullptr;
        }
        else {
            nodes[i].left = &nodes[leftIndex];
        }

        if (rightIndex == -1) {
            nodes[i].right = nullptr;
        }
        else {
            nodes[i].right = &nodes[rightIndex];
        }
    }

    int maxSum = INT_MIN;
    findMaxPath(&nodes[0], maxSum);

    cout << maxSum << endl;

    delete[] nodes;

    return 0;
}
